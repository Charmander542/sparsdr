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

#include <sparsdr/simple_band_spec.h>
// pydoc.h is automatically generated in the build directory
// #include <simple_band_spec_pydoc.h>

void bind_simple_band_spec(py::module& m)
{

    using simple_band_spec = ::gr::sparsdr::simple_band_spec;


    py::class_<simple_band_spec> (m, "simple_band_spec")

        .def(py::init<float, float>(),
             py::arg("frequency"),
             py::arg("bandwidth"))
        .def(py::init<>())


        .def("frequency",
             &simple_band_spec::frequency)


        .def("bandwidth",
             &simple_band_spec::bandwidth)

        ;

} 