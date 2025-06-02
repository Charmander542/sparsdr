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

#include <sparsdr/simple_combined_pluto_receiver.h>

void bind_simple_combined_pluto_receiver(py::module& m)
{
    using simple_combined_pluto_receiver = ::gr::sparsdr::simple_combined_pluto_receiver;

    py::class_<simple_combined_pluto_receiver, gr::hier_block2,
            std::shared_ptr<simple_combined_pluto_receiver>> (m, "simple_combined_pluto_receiver")

        .def(py::init(&simple_combined_pluto_receiver::make))
        ;
} 