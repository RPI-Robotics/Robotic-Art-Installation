# Robotic Art Installation

This project is an interactive robotic art installation created by the Rensselaer Polytechnic Institute (RPI) Robotics Club. The goal is to bridge the gap between art and engineering through a programmable, motion-based artistic display powered by a custom C++ software stack.

---

## 🧰 Prerequisites

This project is developed in **C++** and uses:

- **CMake** for the build system
- **vcpkg** for dependency management
- **g++/clang** as a C++ compiler (with C++17 support)

Tested on **Ubuntu 22.04+** and **Windows 10+** (with WSL or Visual Studio)

---

## 🛠️ Installing Dependencies

### Step 1: Install Required Tools

#### On Ubuntu:
```bash
sudo apt install -y git cmake g++ build-essential
```

### Step 2: Clone the Repository
```bash
git clone https://github.com/RPI-Robotics/Robotic-Art-Installation.git
cd Robotic-Art-Installation
```

### Step 3: Install vcpkg
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh  # or .\bootstrap-vcpkg.bat on Windows
```

### Step 4: Install Dependencies
```bash
./vcpkg/vcpkg install
```

## Building the Project
From the root directory:
### Step 1: Configure the Project
```bash
cmake --preset default
```
### Step 2: Build It
```bash
cmake --build --preset default
```

## Running the program
```bash
./build/RAI
```
