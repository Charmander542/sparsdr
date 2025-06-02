# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT sparsdr_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT sparsdr_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

# Define the source files with full paths
set(sparsdr_python_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/band_spec_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_band_spec_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/reconstruct_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/compressing_pluto_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/iio_device_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/swap_16_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/combined_pluto_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_combined_pluto_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/compressing_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/python_bindings.cc)

# Ensure the source files exist
foreach(source ${sparsdr_python_sources})
    if(NOT EXISTS ${source})
        message(FATAL_ERROR "Source file ${source} does not exist")
    endif()
endforeach()

# Create the Python module
pybind11_add_module(sparsdr_python ${sparsdr_python_sources})

# Set the target properties
set_target_properties(sparsdr_python PROPERTIES
    OUTPUT_NAME "sparsdr"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python/sparsdr
)

# Link against GNU Radio libraries
target_link_libraries(sparsdr_python
    PRIVATE
    gnuradio::gnuradio-runtime
    gnuradio::gnuradio-blocks
    gnuradio::gnuradio-pdu
    gnuradio-sparsdr
)

# Include directories
target_include_directories(sparsdr_python
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib
)

# Install the Python module
install(TARGETS sparsdr_python
    LIBRARY DESTINATION ${GR_PYTHON_DIR}/sparsdr
)

# copy bindings extension for use in QA tests
add_custom_command(TARGET sparsdr_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sparsdr_python>
    ${CMAKE_BINARY_DIR}/test_modules/sparsdr/
) 
