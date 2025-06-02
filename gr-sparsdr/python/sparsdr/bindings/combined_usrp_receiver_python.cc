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

#include <sparsdr/combined_usrp_receiver.h>

void bind_combined_usrp_receiver(py::module& m)
{
    using combined_usrp_receiver = ::gr::sparsdr::combined_usrp_receiver;

    py::class_<combined_usrp_receiver, gr::hier_block2,
            std::shared_ptr<combined_usrp_receiver>> (m, "combined_usrp_receiver")

        .def(py::init(&combined_usrp_receiver::make))
        ;
} 