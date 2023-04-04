# thread_for_clang_example

This repository contains a minimal example that causes a Clang segmentation fault with both the hipcc compiler provided as part of the ROCm 5.4.3, and with  the develop head commit at the time of writing [c3824d8241ebd447516f4673610303094d251bff](https://github.com/ROCm-Developer-Tools/HIPCC/tree/c3824d8241ebd447516f4673610303094d251bff).

**The segmentation fault occurs when a template member function uses a `#pragma omp parallel for schedule(static)` which calls a non-template member function. This is shown in main.cpp**.

Below are the steps to reproduce the segmentation fault.

## Environment and autotools configuration
1) Install ROCm 5.4.3 on Ubuntu v20.04 following [the AMD installation docs](https://docs.amd.com/bundle/ROCm-Installation-Guide-v5.4.3/page/How_to_Install_ROCm.html).
```
sudo apt-get update
wget https://repo.radeon.com/amdgpu-install/5.4.3/ubuntu/focal/amdgpu-install_5.4.50403-1_all.deb  
sudo apt-get install ./amdgpu-install_5.4.50403-1_all.deb
sudo amdgpu-install --usecase=rocm
```
2) Optionally compile the develop version of hipcc, or stay with the version included with the 5.4.3 ROCm distribution.
3) Clone this repository with `git clone https://github.com/srijitpaul/thread_for_clang_example.git`.
4) In `thread_for_clang_example` run `./bootstrap.sh` to execute `autoreconf`.
5) Create an out-of-source build directory and `cd` into it with `mkdir build; cd build`
6) Environment is now set up.

## Segfault reproduction
1) From `thread_for_clang_example/build`, run `../configure CXX=hipcc CXXFLAGS="-std=c++14 -fno-strict-aliasing -fopenmp"`
2) After configuring, run `make`.
3) Clang will raise a segmentation fault.

A segfault will not be raised by not passing the `-fopenmp` CXX flag.
1) From `thread_for_clang_example/build`, run `../configure CXX=hipcc CXXFLAGS="-std=c++14 -fno-strict-aliasing"`
2) After configuring, run `make`.
3) An executable will be produced.
