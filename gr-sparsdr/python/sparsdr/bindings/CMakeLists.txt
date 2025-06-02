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

set(sparsdr_python_files
    band_spec_python.cc
    simple_band_spec_python.cc
    reconstruct_python.cc
    compressing_usrp_source_python.cc
    compressing_pluto_source_python.cc
    iio_device_source_python.cc
    swap_16_python.cc
    combined_usrp_receiver_python.cc
    combined_pluto_receiver_python.cc
    simple_combined_pluto_receiver_python.cc
    simple_combined_usrp_receiver_python.cc
    compressing_source_python.cc
    python_bindings.cc)

# Set the source files for the bindings
set(sparsdr_python_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/band_spec_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_band_spec_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/reconstruct_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/compressing_usrp_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/compressing_pluto_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/iio_device_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/swap_16_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/combined_usrp_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/combined_pluto_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_combined_pluto_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_combined_usrp_receiver_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/compressing_source_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/python_bindings.cc)

GR_PYBIND_MAKE_OOT(sparsdr
   ../../..
   gr::sparsdr
   "${sparsdr_python_sources}")

# copy bindings extension for use in QA tests
add_custom_command(TARGET sparsdr_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sparsdr_python>
    ${CMAKE_BINARY_DIR}/test_modules/sparsdr/
) 