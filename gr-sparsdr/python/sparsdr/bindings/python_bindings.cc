/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

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

// We need this hack because import_array() returns NULL
// for newer Python versions.
// This function is also necessary because it ensures access to the C API
// and removes a warning.
void* init_numpy()
{
    import_array();
    return NULL;
}

PYBIND11_MODULE(sparsdr_python, m)
{
    // Initialize the numpy C API
    // (otherwise we will see segmentation faults)
    init_numpy();

    // Allow access to base block methods
    py::module::import("gnuradio.gr");

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