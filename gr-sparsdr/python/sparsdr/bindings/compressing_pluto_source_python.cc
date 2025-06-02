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

#include <sparsdr/compressing_pluto_source.h>

void bind_compressing_pluto_source(py::module& m)
{
    using compressing_pluto_source = ::gr::sparsdr::compressing_pluto_source;

    py::class_<compressing_pluto_source, gr::hier_block2,
           std::shared_ptr<compressing_pluto_source>>(m, "compressing_pluto_source")


        .def(py::init(&compressing_pluto_source::make))
        ;
} 
