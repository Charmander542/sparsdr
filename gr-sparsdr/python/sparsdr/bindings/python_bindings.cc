/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

// Required for NumPy C API
//#include <numpy/arrayobject.h>

namespace py = pybind11;

// Headers for binding functions
void bind_band_spec(py::module& m);
void bind_simple_band_spec(py::module& m);
void bind_reconstruct(py::module& m);
void bind_compressing_usrp_source(py::module& m);
void bind_compressing_pluto_source(py::module& m);
void bind_iio_device_source(py::module& m);
void bind_swap_16(py::module& m);
void bind_combined_usrp_receiver(py::module& m);
void bind_combined_pluto_receiver(py::module& m);
void bind_simple_combined_pluto_receiver(py::module& m);
void bind_simple_combined_usrp_receiver(py::module& m);
void bind_compressing_source(py::module& m);


PYBIND11_MODULE(sparsdr_python, m)
{
    
    // If you're using GNU Radio base block support
    py::module::import("gnuradio.gr");

    // Bind all module components
    bind_band_spec(m);
    bind_simple_band_spec(m);
    bind_reconstruct(m);
    bind_compressing_usrp_source(m);
    bind_compressing_pluto_source(m);
    bind_iio_device_source(m);
    bind_swap_16(m);
    bind_combined_usrp_receiver(m);
    bind_combined_pluto_receiver(m);
    bind_simple_combined_pluto_receiver(m);
    bind_simple_combined_usrp_receiver(m);
    bind_compressing_source(m);
}

