#!/bin/bash
FLAGS=
# PCIE: ROCKCHIP_PCIE30
# Display Support: ROCKCHIP_VOPEN
#case "$1" in
#        rk3568 | RK3568 | 3568)
#                CHIP=3568;
#                ;;
#        ACPI)
#                CHIP=3588;
#                FLAGS="-D ROCKCHIP_ACPIEN"
#                ;;
#        *)
#                CHIP=3588
#                FLAGS="-D ROCKCHIP_ACPIEN -D ROCKCHIP_PCIE30 -D ROCKCHIP_VOPEN"
#                ;;
#esac

CHIP=3588
FLAGS="-D ROCKCHIP_ACPIEN -D ROCKCHIP_PCIE30 -D ROCKCHIP_VOPEN" # UNUSED Here
echo Start to build Rock 5b UEFI

CMD=`realpath $0`
COMMON_DIR=`dirname $CMD`
TOP_DIR=$(realpath $COMMON_DIR/..)
echo $TOP_DIR

export WORKSPACE=$COMMON_DIR

./build_uefi.sh &&
echo "cd u-boot and re-packet uboot.img: ./scripts/fit-repack.sh -f uboot.img -d unpack/" &&
cd ../u-boot &&
mkdir -p unpack &&

# ./make.sh rk$CHIP CROSS_COMPILE=$TOP_DIR/prebuilts/gcc/linux-x86/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu- &&
./make.sh rock-5b-rk3588 CROSS_COMPILE=$TOP_DIR/prebuilts/gcc/linux-x86/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu- &&
./make.sh --idblock
cp uboot.img uboot_uefi.img
cp $WORKSPACE/Build/RK$CHIP/DEBUG_CLANG38/FV/BL33_AP_UEFI.Fv unpack/uboot &&    # PEI
./scripts/fit-repack.sh -f uboot_uefi.img -d unpack/                            # Replace U-Boot
mv uboot_uefi.img $WORKSPACE/Build/uboot_uefi.img

# Path modification: DO NOT mess up the workspace.
echo "****Build NOR FLASH IMAGE****"
cp $WORKSPACE/Build/RK$CHIP/DEBUG_CLANG38/FV/NOR_FLASH_IMAGE.fd $WORKSPACE/Build/RK3588_NOR_FLASH.img   # DXE/FvMain
dd if=$WORKSPACE/Build/RK3588_NOR_FLASH.img of=$WORKSPACE/Build/NV_DATA.img bs=1K skip=7936             # Skip 7936KB, write the rest of data into NV_DATA.img
dd if=$WORKSPACE/ImageResources/rk3588_spi_nor_gpt.img of=$WORKSPACE/Build/RK3588_NOR_FLASH.img         # OverWrite rk3588_spi_nor_gpt.img onto RK3588_NOR_FLASH.img.
dd if=idblock.bin of=$WORKSPACE/Build/RK3588_NOR_FLASH.img bs=1K seek=32                                # Skip 32KB in RK3588_NOR_FLASH.img, then write idblock.bin
dd if=idblock.bin of=$WORKSPACE/Build/RK3588_NOR_FLASH.img bs=1K seek=544                               # Skip 544KB in RK3588_NOR_FLASH.img, then write idblock.bin
dd if=$WORKSPACE/Build/uboot_uefi.img of=$WORKSPACE/Build/RK3588_NOR_FLASH.img bs=1K seek=1024          # Skip 1024KB in RK3588_NOR_FLASH.img, then write uboot_uefi.img(ATF + xxx + PEI)
dd if=$WORKSPACE/Build/NV_DATA.img of=$WORKSPACE/Build/RK3588_NOR_FLASH.img bs=1K seek=7936             # Skip 7936KB in RK3588_NOR_FLASH.img, then write NV_DATA.img to where it originally put.
echo "FLAGS=:" $FLAGS

# You are not a internal developer
#echo "*********************************************************************"
#echo "** uefi document : https://10.10.10.29/c/rk/internal-docs/+/149726 **"
#echo "*********************************************************************"
