#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

"""
This file contains the necessary configuration for the pybind11 bindings.
"""

import os
import sys

def get_include_dirs():
    """Get the include directories for the bindings."""
    # Get the path to the source directory
    source_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(__file__))))
    
    # Add the include directory
    include_dirs = [
        os.path.join(source_dir, 'include'),
        os.path.join(source_dir, 'lib'),
    ]
    
    return include_dirs

def get_define_macros():
    """Get the define macros for the bindings."""
    return [
        ('SPARSDR_API', ''),
        ('GR_CTRLPORT', '1'),
    ]

def get_extra_compile_args():
    """Get the extra compile arguments for the bindings."""
    return []

def get_extra_link_args():
    """Get the extra link arguments for the bindings."""
    return [] 