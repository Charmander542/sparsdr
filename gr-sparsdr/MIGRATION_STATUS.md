# GNU Radio 3.8 to 3.10 Migration Status

This document tracks the migration progress from GNU Radio 3.8 to 3.10.

## Completed Changes

### 1. CMakeLists.txt Updates
- ✅ Updated CMake minimum version from 3.8 to 3.16.3
- ✅ Changed GNU Radio version requirement from 3.8 to 3.10
- ✅ Added `pdu` component to GNU Radio dependencies
- ✅ Updated C++ standard from C++11 to C++17
- ✅ Added Python setup and pygccxml check
- ✅ Removed SWIG subdirectory, added pybind11 support
- ✅ Fixed VERSION_PATCH from "git" to "0"

### 2. Python Bindings Migration (SWIG → pybind11)
- ✅ Created new pybind11 bindings directory structure: `python/sparsdr/bindings/`
- ✅ Created main binding file: `python_bindings.cc`
- ✅ Created individual binding files for all blocks:
  - `band_spec_python.cc`
  - `simple_band_spec_python.cc`
  - `reconstruct_python.cc`
  - `compressing_usrp_source_python.cc`
  - `compressing_pluto_source_python.cc`
  - `iio_device_source_python.cc`
  - `swap_16_python.cc`
  - `combined_usrp_receiver_python.cc`
  - `combined_pluto_receiver_python.cc`
  - `simple_combined_pluto_receiver_python.cc`
  - `simple_combined_usrp_receiver_python.cc`
  - `compressing_source_python.cc`
- ✅ Created bindings CMakeLists.txt with GR_PYBIND_MAKE_OOT
- ✅ Updated python CMakeLists.txt to include bindings subdirectory
- ✅ Updated python/__init__.py to import from pybind11 module instead of SWIG

### 3. Header Updates
- ✅ Replaced `boost::shared_ptr` with `std::shared_ptr` in all headers
- ✅ Added `#include <memory>` where needed
- ✅ Updated reconstruct.h, compressing_usrp_source.h, and combined_usrp_receiver.h

### 4. Implementation Updates
- ✅ Updated ALL implementation files to use `gr::make_block_sptr<>()` instead of `gnuradio::get_initial_sptr()`:
  - ✅ `swap_16_impl.cc`
  - ✅ `compressing_usrp_source_impl.cc`
  - ✅ `simple_combined_usrp_receiver_impl.cc`
  - ✅ `simple_combined_pluto_receiver_impl.cc`
  - ✅ `reconstruct_impl.cc`
  - ✅ `iio_device_source_impl.cc`
  - ✅ `compressing_pluto_source_impl.cc`
  - ✅ `combined_usrp_receiver_impl.cc`
  - ✅ `combined_pluto_receiver_impl.cc`

### 5. Boost Modernization and Removal
- ✅ Replaced `boost::lexical_cast` with `std::to_string()` and `std::stoul()` in all files
- ✅ Replaced `boost::noncopyable` with deleted copy constructor/assignment in `reconstruct_impl.h`
- ✅ Removed unused `boost::make_shared` include from `endian_converter.cc`
- ✅ **Completely removed Boost dependency** from CMakeLists.txt (only header-only Boost.Test remains for unit tests)
- ✅ Modernized code to use C++17 standard library instead of Boost equivalents

## Remaining Work

### 1. Additional Header Updates (if needed)
- ⚠️ May need to add `#include <memory>` to remaining headers that use `std::shared_ptr`

### 2. Testing and Building
- [ ] Test the build with the new configuration
- [ ] Fix any compilation errors
- [ ] Test Python imports
- [ ] Update any deprecated API usage discovered during build

## ✅ **Migration Complete - Ready for Testing**

All major migration work has been completed! The following changes have been successfully implemented:

1. **Build System**: CMake 3.16.3+, GNU Radio 3.10+, C++17
2. **Python Bindings**: Complete migration from SWIG to pybind11
3. **Smart Pointers**: All boost::shared_ptr → std::shared_ptr conversions
4. **Block Creation**: All gnuradio::get_initial_sptr → gr::make_block_sptr updates
5. **Dependencies**: Added gr-pdu component

## Next Steps

1. **Test Build**: Run `./test_build.sh` or manually build to identify any remaining issues
2. **Fix Compilation Issues**: Address any compiler errors that arise
3. **Test Python Module**: Verify the pybind11 bindings work correctly
4. **Integration Testing**: Test the GNU Radio blocks in flowgraphs

## References

- [GNU Radio 3.10 OOT Module Porting Guide](https://wiki.gnuradio.org/index.php/GNU%5FRadio%5F3.10%5FOOT%5FModule%5FPorting%5FGuide)
- [GNU Radio 3.10 Migration Documentation](https://wiki.gnuradio.org/index.php/Porting%5FExisting%5FFlowgraphs%5Fto%5Fa%5FNewer%5FVersion) 