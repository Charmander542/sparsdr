/* -*- c++ -*- */
/*
 * Copyright 2019-2022 The Regents of the University of California.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_SPARSDR_COMPRESSING_USRP_SOURCE_H
#define INCLUDED_SPARSDR_COMPRESSING_USRP_SOURCE_H

#include <gnuradio/sync_block.h>
#include <sparsdr/api.h>
#include <sparsdr/compressing_source.h>
#include <uhd/types/device_addr.hpp>
#include <uhd/types/tune_request.hpp>
#include <uhd/types/tune_result.hpp>
#include <memory>

namespace gr {
namespace sparsdr {

/*!
 * \brief A block that wraps a UHD USRP source and allows SparSDR
 * compression settings to be changed
 * \ingroup sparsdr
 *
 */
class SPARSDR_API compressing_usrp_source : virtual public gr::sync_block,
                                            public compressing_source
{
public:
    typedef std::shared_ptr<compressing_usrp_source> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of sparsdr::compressing_usrp_source.
     *
     * To avoid accidental use of raw pointers, sparsdr::compressing_usrp_source's
     * constructor is in a private implementation
     * class. sparsdr::compressing_usrp_source::make is the public interface for
     * creating new instances.
     */
    static sptr make(const ::uhd::device_addr_t& device_addr);

    // Begin general USRP settings

    /*!
     * Set the gain.
     *
     * \param gain the gain in dB
     */
    virtual void set_gain(double gain) = 0;

    /*!
     * Tune to the desired center frequency.
     *
     * \param tune_request the tune request instructions
     * \return a tune result with the actual frequencies
     */
    virtual ::uhd::tune_result_t
    set_center_freq(const ::uhd::tune_request_t& tune_request) = 0;

    /*!
     * Set the antenna to use.
     *
     * \param ant the antenna string
     */
    virtual void set_antenna(const std::string& ant) = 0;

    virtual void set_compression_enabled(bool enabled) = 0;
    virtual void set_run_fft(bool enable) = 0;
    virtual void set_send_fft_samples(bool enable) = 0;
    virtual void set_send_average_samples(bool enable) = 0;
    virtual void set_fft_size(std::uint32_t size) = 0;
    virtual std::uint32_t fft_size() const = 0;
    virtual void set_shift_amount(std::uint8_t scaling) = 0;
    virtual void set_bin_threshold(std::uint16_t index, std::uint32_t threshold) = 0;
    virtual void set_bin_window_value(std::uint16_t bin_index, std::uint16_t value) = 0;
    virtual void set_bin_mask(std::uint16_t bin_index) = 0;
    virtual void clear_bin_mask(std::uint16_t bin_index) = 0;
    virtual void set_average_weight(float weight) = 0;
    virtual void set_average_interval(std::uint32_t interval) = 0;
};

} // namespace sparsdr
} // namespace gr

#endif /* INCLUDED_SPARSDR_COMPRESSING_USRP_SOURCE_H */
