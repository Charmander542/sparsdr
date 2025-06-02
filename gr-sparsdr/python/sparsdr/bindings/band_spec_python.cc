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

#include <sparsdr/band_spec.h>
// pydoc.h is automatically generated in the build directory
// #include <band_spec_pydoc.h>

void bind_band_spec(py::module& m)
{

    using band_spec = ::gr::sparsdr::band_spec;


    py::class_<band_spec> (m, "band_spec")

        .def(py::init<float, std::uint16_t>(),
             py::arg("frequency"),
             py::arg("bins"))
        .def(py::init<>())


        .def("frequency",
             &band_spec::frequency)


        .def("bins",
             &band_spec::bins)

        ;

} 