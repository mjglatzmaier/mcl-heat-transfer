# MCL-Heat-Transfer
Heat transfer solver used in the multiphysics compute package.

---

## Features
- Solution to the heat equation
---

## Prerequisites
Before setting up MCL-Heat-Transfer, ensure the following are installed on your Linux system:
- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/)
- Ninja Build System (`sudo apt-get install ninja`)
- A C++17 compliant compiler (e.g., GCC 9+ or Clang)

---

## Setting Up Dependencies

Follow the steps below to set up dependencies using [vcpkg](https://github.com/microsoft/vcpkg):

1. **Clone and Bootstrap vcpkg**:
   ```bash
   cd <desired-install-dir>
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh

2. **Install Required Libraries: Add vcpkg to your system's PATH and install the necessary libraries**:
   ```bash
   export PATH=<vcpkg-install-path>/vcpkg:$PATH
   source ~/.bashrc
   ./vcpkg install gtest spdlog yaml-cpp

3. **Configure the Project: Edit the CMakePresets.json file in the project root to point the toolchain to vcpkg**:
   ```bash  
   "toolchainFile": "/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"

4. **Install the Ninja Build System (if not already installed)**
   ```bash
   sudo apt-get install ninja

---

## Building the project

Build either in debug or release mode (more options to follow),

   ```bash
   cmake --preset=release
   cmake --build build/release
   ```

## Contribution Guidelines

Contributions welcome! Please follow these steps:

 - Fork the repository and clone your fork locally.
 - Create a feature branch for your changes.
 - Commit changes with clear and concise messages.
 - Submit a pull request with a detailed description of the changes.