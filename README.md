# UEFI Implement For Radxa Rock5b.
> **UEFI Source are pulled from Public Rockchip SDK on [GitLab](https://gitlab.com/rk3588_linux/rk/uefi-monorepo).**

## Build Instructions.

1. Setup build environment.
```
./setup_env.sh
```

2. Collect Tools and Source.
```
# u-boot
git clone https://github.com/radxa/u-boot -b stable-5.10-rock5 u-boot

# rkbin
git clone https://gitlab.com/rk3588_linux/rk/rkbin rkbin

# prebuilt gcc (to build u-boot)
git clone https://github.com/Fruit-Pi/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu prebuilt/gcc/linux-x86/aarch64/

# Uefi 
git clone https://github.com/sunflower2333/Rock5bPkg
```

3. Run build script
```
cd Rock5bPkg
./make.sh
```

## Boot Instructions
Flash `RK3588_NOR_FLASH.img` into SD card or NOR, then boot it !


## Notice
In fact I can provide a idblock/uboot.img binary here, but build from source is better.  
This repo is based on RK official uefi repo in SDK.  


## License
**BSD-2-Clause-Patent.**
