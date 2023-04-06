# UEFI Implement For Radxa Rock5b.
> **UEFI Source are pulled from Public Rockchip SDK on [GitLab](https://gitlab.com/rk3588_linux/rk/uefi-monorepo).**

## Build Instructions.

1. Install Build Tools
```
./setup_env.sh
```

2. Collect Tools and Source.
```
# u-boot
git clone https://github.com/radxa/u-boot -b stable-5.10-rock5

# prebuilt gcc (to build u-boot)
mkdir -p prebuilt/gcc/linux-x86/aarch64/
git clone https://github.com/FireflyTeam/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu prebuilt/gcc/linux-x86/aarch64/

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


## License
**BSD-2-Clause-Patent.**
