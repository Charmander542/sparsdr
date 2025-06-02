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

#include <sparsdr/swap_16.h>

void bind_swap_16(py::module& m)
{
    using swap_16 = ::gr::sparsdr::swap_16;

    py::class_<swap_16, gr::sync_block,
            std::shared_ptr<swap_16>> (m, "swap_16")

        .def(py::init(&swap_16::make))
        ;
} 