#!/bin/bash

# GNU Radio 3.10 Migration Test Build Script

echo "Starting GNU Radio 3.10 migration test build..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
echo "Configuring with CMake..."
cmake .. || {
    echo "CMake configuration failed!"
    exit 1
}

# Build the project
echo "Building project..."
make -j$(nproc) || {
    echo "Build failed!"
    exit 1
}

echo "Build completed successfully!"
echo "To install, run: sudo make install" 