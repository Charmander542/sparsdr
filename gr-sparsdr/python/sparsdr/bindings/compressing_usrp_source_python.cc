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

#include <sparsdr/compressing_usrp_source.h>

void bind_compressing_usrp_source(py::module& m)
{
    using compressing_usrp_source = ::gr::sparsdr::compressing_usrp_source;

    py::class_<compressing_usrp_source, gr::sync_block,
            std::shared_ptr<compressing_usrp_source>> (m, "compressing_usrp_source")

        .def(py::init(&compressing_usrp_source::make),
             py::arg("device_addr")
             )
        ;
} 