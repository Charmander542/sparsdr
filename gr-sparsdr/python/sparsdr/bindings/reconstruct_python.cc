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

#include <sparsdr/reconstruct.h>
// pydoc.h is automatically generated in the build directory
// #include <reconstruct_pydoc.h>

void bind_reconstruct(py::module& m)
{

    using reconstruct = ::gr::sparsdr::reconstruct;


    py::class_<reconstruct, gr::hier_block2,
            std::shared_ptr<reconstruct>> (m, "reconstruct")

        .def(py::init(&reconstruct::make),
             py::arg("bands"),
             py::arg("reconstruct_path") = "sparsdr_reconstruct",
             py::arg("sample_format") = "N210 v1",
             py::arg("zero_gaps") = false,
             py::arg("compression_fft_size") = 1024
             )
        ;

} 