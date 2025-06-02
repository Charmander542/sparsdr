/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <sparsdr/iio_device_source.h>
#include <iio.h>  // Assuming you're using libiio

namespace {

/**
 * Helper function to open an IIO device by URI and channel name
 */
iio_device* open_iio_device(const std::string& uri, const std::string& channel)
{
    struct iio_context* ctx = iio_create_context_from_uri(uri.c_str());
    if (!ctx) {
        throw std::runtime_error("Failed to create IIO context from URI: " + uri);
    }

    struct iio_device* dev = iio_context_find_device(ctx, "cf-ad9361-A");  // You may want to make this configurable
    if (!dev) {
        iio_context_destroy(ctx);
        throw std::runtime_error("Failed to find device in IIO context");
    }

    return dev; // ⚠️ Note: you must manage the lifetime of this device and context carefully.
}

} // anonymous namespace

void bind_iio_device_source(py::module& m)
{
    using iio_device_source = ::gr::sparsdr::iio_device_source;

    py::class_<iio_device_source, gr::sync_block,
               std::shared_ptr<iio_device_source>>(m, "iio_device_source")
        .def_static(
            "make",
            [](const std::string& uri,
               const std::string& channel,
               std::size_t buffer_size_samples) {
                iio_device* dev = open_iio_device(uri, channel);
                return iio_device_source::make(dev, channel, buffer_size_samples);
            },
            py::arg("uri"),
            py::arg("channel"),
            py::arg("buffer_size_samples"),
            R"pbdoc(
                Create an iio_device_source block.

                Args:
                    uri: URI for the IIO context (e.g., "ip:192.168.2.1")
                    channel: Channel name (e.g., "voltage0")
                    buffer_size_samples: Number of samples in the buffer

                Returns:
                    A new iio_device_source block.
            )pbdoc");
}

