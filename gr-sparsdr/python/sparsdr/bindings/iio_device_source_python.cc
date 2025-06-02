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

#include <sparsdr/iio_device_source.h>

void bind_iio_device_source(py::module& m)
{
    using iio_device_source = ::gr::sparsdr::iio_device_source;

    py::class_<iio_device_source, gr::sync_block,
            std::shared_ptr<iio_device_source>> (m, "iio_device_source")

        .def(py::init(&iio_device_source::make))
        ;
} 