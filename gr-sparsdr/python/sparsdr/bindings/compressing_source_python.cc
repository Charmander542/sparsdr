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

#include <sparsdr/compressing_source.h>

void bind_compressing_source(py::module& m)
{
    using compressing_source = ::gr::sparsdr::compressing_source;

    py::class_<compressing_source, std::shared_ptr<compressing_source>>(m, "compressing_source")
        .def("set_compression_enabled", &compressing_source::set_compression_enabled)
        .def("set_run_fft", &compressing_source::set_run_fft)
        .def("set_send_average_samples", &compressing_source::set_send_average_samples)
        .def("set_send_fft_samples", &compressing_source::set_send_fft_samples)
        .def("start_all", &compressing_source::start_all)
        .def("stop_all", &compressing_source::stop_all)
        .def("set_fft_size", &compressing_source::set_fft_size)
        .def("fft_size", &compressing_source::fft_size)
        .def("set_shift_amount", &compressing_source::set_shift_amount)
        .def("set_bin_threshold", &compressing_source::set_bin_threshold)
        .def("set_thresholds_from_file", &compressing_source::set_thresholds_from_file)
        .def("set_bin_window_value", &compressing_source::set_bin_window_value)
        .def("load_rounded_hann_window", &compressing_source::load_rounded_hann_window)
        .def("set_bin_mask", &compressing_source::set_bin_mask)
        .def("clear_bin_mask", &compressing_source::clear_bin_mask)
        .def("set_bin_spec", &compressing_source::set_bin_spec)
        .def("set_average_weight", &compressing_source::set_average_weight)
        .def("set_average_interval", &compressing_source::set_average_interval)
        ;
}

