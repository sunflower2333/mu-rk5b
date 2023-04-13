#
#  Copyright (c) 2014-2018, Linaro Limited. All rights reserved.
#  Copyright (c) 2021-2022, Rockchip Limited. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = RK3588
  PLATFORM_GUID                  = d080df36-45e7-11ec-9726-f42a7dcb925d
  PLATFORM_VERSION               = 0.2
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Rock5bPkg/Rock5b.fdf

  DEFINE CONFIG_NO_DEBUGLIB      = TRUE

  DEFINE CP_UNCONNECTED    = 0x0
  DEFINE CP_PCIE           = 0x01
  DEFINE CP_SATA           = 0x10
  DEFINE CP_USB3           = 0x20

  DEFINE ROCKCHIP_ACPIEN = TRUE
#  DEFINE ROCKCHIP_PCIE30 = FALSE
  DEFINE ROCKCHIP_VOPEN  = TRUE

  #
  # Network definition
  #
  DEFINE NETWORK_SNP_ENABLE             = FALSE
  DEFINE NETWORK_IP6_ENABLE             = FALSE
  DEFINE NETWORK_TLS_ENABLE             = FALSE
  DEFINE NETWORK_HTTP_BOOT_ENABLE       = FALSE
  DEFINE NETWORK_ISCSI_ENABLE           = FALSE
  DEFINE NETWORK_VLAN_ENABLE            = FALSE

[BuildOptions]
  GCC:*_*_*_PLATFORM_FLAGS = -I$(WORKSPACE_ROOT)/Silicon/Rockchip/RK3588/Include -I$(WORKSPACE_ROOT)/Platforms/Rock5bPkg/Include -I$(WORKSPACE_ROOT)/Silicon/Rockchip/Rockchip/Include -Wno-unused-function

!include MdePkg/MdeLibs.dsc.inc
!include Rock5bPkg/Rock5b.dsc.inc
!include Rock5bPkg/Frontpage.dsc.inc
!include Rockchip/Rockchip.dsc.inc


[PcdsFixedAtBuild.common]
  gRK3588TokenSpaceGuid.PcdMipiFrameBufferAddress|0xC0000000
  gRK3588TokenSpaceGuid.PcdMipiFrameBufferWidth|1920
  gRK3588TokenSpaceGuid.PcdMipiFrameBufferHeight|1080
  gRK3588TokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32
