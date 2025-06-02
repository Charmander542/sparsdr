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

    py::class_<compressing_source, gr::sync_block,
            std::shared_ptr<compressing_source>> (m, "compressing_source")

        .def(py::init(&compressing_source::make))
        ;
} 