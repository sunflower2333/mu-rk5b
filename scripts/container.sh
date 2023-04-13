# Setup environment
./setup_env.sh

# u-boot
git clone https://github.com/radxa/u-boot -b stable-5.10-rock5 u-boot

# rkbin
git clone https://gitlab.com/rk3588_linux/rk/rkbin rkbin

# prebuilt gcc (to build u-boot)
git clone https://github.com/Fruit-Pi/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu prebuilt/gcc/linux-x86/aarch64/

# Uefi
git clone https://github.com/sunflower2333/Rock5bPkg

# Build
./make.sh
