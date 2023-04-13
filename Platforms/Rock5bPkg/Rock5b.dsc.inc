## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

[BuildOptions.common]
  *_CLANG38_AARCH64_CC_FLAGS = -Wno-unused-const-variable -Wno-sometimes-uninitialized -Wno-unaligned-access -D CLANG
  *_*_*_CC_FLAGS = -march=armv8.2-a+crypto+rcpc 
#  *_*_*_PP_FLAGS = -DICC_SGI1R=ICC_SGI1R_EL1

[BuildOptions.common.EDKII.DXE_CORE,BuildOptions.common.EDKII.DXE_DRIVER,BuildOptions.common.EDKII.UEFI_DRIVER,BuildOptions.common.EDKII.UEFI_APPLICATION]
  *_*_*_DLINK_FLAGS = -z common-page-size=0x1000

[BuildOptions.common.EDKII.DXE_RUNTIME_DRIVER]
  *_*_ARM_DLINK_FLAGS = -z common-page-size=0x1000
  *_*_AARCH64_DLINK_FLAGS = -z common-page-size=0x10000

[PcdsFeatureFlag.common]
  gArmTokenSpaceGuid.PcdCpuDxeProduceDebugSupport|FALSE

  gEfiMdePkgTokenSpaceGuid.PcdComponentNameDisable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdDriverDiagnosticsDisable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdComponentName2Disable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdDriverDiagnostics2Disable|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdTurnOffUsbLegacySupport|TRUE
  #  If TRUE, Graphics Output Protocol will be installed on virtual handle created by ConsplitterDxe.
  #  It could be set FALSE to save size.
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutGopSupport|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdSupportUpdateCapsuleReset|TRUE

  gEmbeddedTokenSpaceGuid.PcdPrePiProduceMemoryTypeInformationHob|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdPciBusHotplugDeviceSupport|FALSE

  gEfiMdeModulePkgTokenSpaceGuid.PcdInstallAcpiSdtProtocol|TRUE

[PcdsFixedAtBuild.common]
  #
  # Make VariableRuntimeDxe work at emulated non-volatile variable mode.
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable|TRUE

  gEmbeddedTokenSpaceGuid.PcdPrePiCpuIoSize|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIReclaimMemory|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIMemoryNVS|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiReservedMemoryType|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesData|300
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesCode|150
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesCode|1000
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesData|800
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderCode|10
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderData|0

  ## Default Terminal Type
  ## 0-PCANSI, 1-VT100, 2-VT00+, 3-UTF8, 4-TTYTERM
  gEfiMdePkgTokenSpaceGuid.PcdDefaultTerminalType|4

  # Boot Manager
  gEfiMdePkgTokenSpaceGuid.PcdPlatformBootTimeOut|2

  # PCI Express
  gEfiMdeModulePkgTokenSpaceGuid.PcdSrIovSupport|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdAriSupport|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdMrIovSupport|FALSE
  gArmTokenSpaceGuid.PcdPciBusMin|0x0
  gArmTokenSpaceGuid.PcdPciBusMax|0xff

  # Sec
  #gEfiMdeModulePkgTokenSpaceGuid.PcdMaxAuthVariableSize|0x2800
  #gEfiSecurityPkgTokenSpaceGuid.PcdUserPhysicalPresence|TRUE

  # System Memory (1GB)
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x00000000
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x40000000
  gRK3588TokenSpaceGuid.PcdTotalMemorySize|0x200000000

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVersionString|L"Alpha"

  # RK3588 CPU profile
  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|2

  # I2C
  gRockchipTokenSpaceGuid.PcdI2cSlaveAddresses|{ 0x51 }
  gRockchipTokenSpaceGuid.PcdI2cSlaveBuses|{ 0x2 }
  gRockchipTokenSpaceGuid.PcdI2cControllersEnabled|{ 0x2 }
  gRockchipTokenSpaceGuid.PcdI2cClockFrequency|198000000
  gRockchipTokenSpaceGuid.PcdI2cBaudRate|100000
  gRockchipTokenSpaceGuid.PcdI2cBusCount|1
  gRockchipTokenSpaceGuid.PcdI2cDemoAddresses|{ 0x51 } #/* RTCYM8563TS 0x51@bus2 */
  gRockchipTokenSpaceGuid.PcdI2cDemoBuses|{ 0x2 }

  ## UART2 - Serial Terminal
  DEFINE SERIAL_BASE = 0xFEB50000 # UART2
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialRegisterBase|$(SERIAL_BASE)
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultBaudRate|1500000
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultDataBits|8
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultParity|1
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultStopBits|1

  ## SPI - SPI2 for test
  gRockchipTokenSpaceGuid.SpiTestBaseAddr|0xFEB20000
  gRockchipTokenSpaceGuid.SpiRK806BaseAddr|0xFEB20000
  #gRockchipTokenSpaceGuid.PcdSpiVariableOffset|0x3C0000

  ## PL031 RealTimeClock
  #gArmPlatformTokenSpaceGuid.PcdPL031RtcBase|0xF8003000

  ## NOR FLASH
  gRockchipTokenSpaceGuid.FspiBaseAddr|0xFE2B0000

  ## CRU
  gRockchipTokenSpaceGuid.CruBaseAddr|0xFD7C0000

  #
  # ARM General Interrupt Controller
  #
  gArmTokenSpaceGuid.PcdGicDistributorBase|0xfe600000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0xfe600000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0xfe680000

  #
  # DW SD card controller
  #
#  gDesignWareTokenSpaceGuid.PcdDwEmmcDxeBaseAddress|0xfe2c0000
#  gDesignWareTokenSpaceGuid.PcdDwEmmcDxeClockFrequencyInHz|100000000
#  gDesignWareTokenSpaceGuid.PcdDwPermitObsoleteDrivers|TRUE
#  gDesignWareTokenSpaceGuid.PcdDwEmmcDxeFifoDepth|256
  #
  # SDHCI controller
  #
  gRockchipTokenSpaceGuid.PcdSdhciDxeBaseAddress|0xfe2e0000

  #
  # PCIe controller
  #
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4ApbBaseAddress|0xfe150000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4DbiBaseAddress|0xf5000000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4CfgBaseAddress|0xf0000000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4CfgSize|0x100000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4IoBaseAddress|0xf0100000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4IoSize|0x10000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4MemBaseAddress|0xf0200000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4MemSize|0xe00000
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4MemBaseAddress64|0x901000000 #deduct 0x1000000 ECAM space
  gRockchipTokenSpaceGuid.PcdPcieRootPort3x4MemSize64|0x3f000000

  #
  # Fastboot
  #
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbVendorId|0x2207
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbProductId|0x0001

  #
  # USB OHCI controller
  #
  gRockchipTokenSpaceGuid.PcdOhciBaseAddress|0xfc840000
  gRockchipTokenSpaceGuid.PcdNumOhciController|2
  gRockchipTokenSpaceGuid.PcdOhciSize|0x80000

  #
  # USB2 EHCI controller
  #
  gRockchipTokenSpaceGuid.PcdEhciBaseAddress|0xfc800000
  gRockchipTokenSpaceGuid.PcdNumEhciController|2
  gRockchipTokenSpaceGuid.PcdEhciSize|0x80000

  #
  # DWC3 controller
  #
  gRockchipTokenSpaceGuid.PcdDwc3BaseAddress|0xfc000000
  gRockchipTokenSpaceGuid.PcdNumDwc3Controller|2
  gRockchipTokenSpaceGuid.PcdDwc3Size|0x400000

  #
  # USB XHCI controller
  #
  gRockchipTokenSpaceGuid.PcdXhciBaseAddress|0xfc000000
  gRockchipTokenSpaceGuid.PcdNumXhciController|2
  gRockchipTokenSpaceGuid.PcdXhciSize|0x400000

  #
  # Android Loader
  #
  gRK3588TokenSpaceGuid.PcdAndroidBootDevicePath|L"\\EFI\\BOOT\\GRUBAA64.EFI"
  gRK3588TokenSpaceGuid.PcdSdBootDevicePath|L"VenHw(0D51905B-B77E-452A-A2C0-ECA0CC8D514A,00E023F70000000000)/SD(0x0)"
  gRK3588TokenSpaceGuid.PcdKernelBootArg|L"earlycon=uart8250,mmio32,0xfeb50000 root=PARTUUID=614e0000-0000 rw rootwait"
  gEmbeddedTokenSpaceGuid.PcdAndroidBootDevicePath|L"VenHw(100C2CFA-B586-4198-9B4C-1683D195B1DA)/HD(3,GPT,7A3F0000-0000-446A-8000-702F00006273,0x8000,0x20000)"

  #
  # Make VariableRuntimeDxe work at emulated non-volatile variable mode.
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable|TRUE

# ACPI Enable
!ifdef $(ROCKCHIP_ACPIEN)
  gRK3588TokenSpaceGuid.AcpiEnable|TRUE
!endif

  #
  # Display
  #
  gRockchipTokenSpaceGuid.PcdLcdPixelFormat|0x00000001
  gRockchipTokenSpaceGuid.PcdEdpId|0x00000000 #edp0
  #gRockchipTokenSpaceGuid.PcdEdpId|0x00000001 #edp1
  gRockchipTokenSpaceGuid.PcdHdmiId|0x00000001 #hdmi1
  #gRockchipTokenSpaceGuid.PcdHdmiId|0x00000001 #hdmi1

  #
  # ComboPhy
  #
  gRockchipTokenSpaceGuid.PcdComboPhyMode|{ $(CP_SATA), $(CP_USB3), $(CP_PCIE) }


  # a PCD that controls the enumeration and connection of ConIn's. When true, ConIn is only connected once a console input is requests
  gEfiMdeModulePkgTokenSpaceGuid.PcdConInConnectOnDemand|FALSE

  # Enable SHELL to build instead of just taking the binary
  gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|16000
  gEfiShellPkgTokenSpaceGuid.PcdShellProfileMask|0x1f    # All profiles

  gMsGraphicsPkgTokenSpaceGuid.PcdUiThemeInDxe|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdBootManagerInBootOrder|TRUE

  # The GUID of Frontpage.inf from MU_OEM_SAMPLE
  # 4042708A-0F2D-4823-AC60-0D77B3111889
  gEfiMdeModulePkgTokenSpaceGuid.PcdBootManagerMenuFile|{ 0x8A, 0x70, 0x42, 0x40, 0x2D, 0x0F, 0x23, 0x48, 0xAC, 0x60, 0x0D, 0x77, 0xB3, 0x11, 0x18, 0x89 }
  gEfiMdeModulePkgTokenSpaceGuid.PcdResetOnMemoryTypeInformationChange|FALSE
  gEmbeddedTokenSpaceGuid.PcdMetronomeTickPeriod|1000

  gOemPkgTokenSpaceGuid.PcdUefiVersionNumber|0x1000001 # 1.00.00.01
  gOemPkgTokenSpaceGuid.PcdUefiBuildDate|0x20230401 # 01/04/2023

  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxVariableSize|0x2000

!include MdePkg/MdeLibs.dsc.inc

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableBase64|0x007C0000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareBase64|0x007CF000
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingBase64|0x007D0000
  #
  # Display
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|180
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|120
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|180
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|120

[LibraryClasses.common]
  AcpiLib|EmbeddedPkg/Library/AcpiLib/AcpiLib.inf
  ArmLib|ArmPkg/Library/ArmLib/ArmBaseLib.inf
  ArmMmuLib|ArmPkg/Library/ArmMmuLib/ArmMmuBaseLib.inf
  ArmGenericTimerCounterLib|ArmPkg/Library/ArmGenericTimerPhyCounterLib/ArmGenericTimerPhyCounterLib.inf
  ArmDisassemblerLib|ArmPkg/Library/ArmDisassemblerLib/ArmDisassemblerLib.inf
  ArmGicLib|ArmPkg/Drivers/ArmGic/ArmGicLib.inf
  ArmHvcLib|ArmPkg/Library/ArmHvcLib/ArmHvcLib.inf
  ArmSmcLib|ArmPkg/Library/ArmSmcLib/ArmSmcLib.inf
  TimerLib|ArmPkg/Library/ArmArchTimerLib/ArmArchTimerLib.inf
  ArmPlatformLib|Rock5bPkg/Library/RK3588Lib/RK3588Lib.inf
  ArmPlatformStackLib|ArmPlatformPkg/Library/ArmPlatformStackLib/ArmPlatformStackLib.inf
  AuthVariableLib|MdeModulePkg/Library/AuthVariableLibNull/AuthVariableLibNull.inf
  AndroidBootImgLib|EmbeddedPkg/Library/AndroidBootImgLib/AndroidBootImgLib.inf
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  BaseSynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  BootLogoLib|MdeModulePkg/Library/BootLogoLib/BootLogoLib.inf
  BmpSupportLib|MdeModulePkg/Library/BaseBmpSupportLib/BaseBmpSupportLib.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  CacheMaintenanceLib|ArmPkg/Library/ArmCacheMaintenanceLib/ArmCacheMaintenanceLib.inf
  CompilerIntrinsicsLib|MdePkg/Library/CompilerIntrinsicsLib/ArmCompilerIntrinsicsLib.inf  # MU_CHANGE
  NULL|MdePkg/Library/CompilerIntrinsicsLib/ArmCompilerIntrinsicsLib.inf  # MU_CHANGE
  NULL|MdePkg/Library/BaseStackCheckLib/BaseStackCheckLib.inf
  CpuExceptionHandlerLib|ArmPkg/Library/ArmExceptionLib/ArmExceptionLib.inf
  CpuLib|MdePkg/Library/BaseCpuLib/BaseCpuLib.inf
  CustomizedDisplayLib|MdeModulePkg/Library/CustomizedDisplayLib/CustomizedDisplayLib.inf
  CruLib|Rockchip/Library/CruLib/CruLib.inf
  DefaultExceptionHandlerLib|ArmPkg/Library/DefaultExceptionHandlerLib/DefaultExceptionHandlerLib.inf
  DebugAgentLib|MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  DmaLib|EmbeddedPkg/Library/NonCoherentDmaLib/NonCoherentDmaLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  DxeServicesTableLib|MdePkg/Library/DxeServicesTableLib/DxeServicesTableLib.inf
  ExtractGuidedSectionLib|EmbeddedPkg/Library/PrePiExtractGuidedSectionLib/PrePiExtractGuidedSectionLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
  FdtLib|EmbeddedPkg/Library/FdtLib/FdtLib.inf
  FrameBufferBltLib|MdeModulePkg/Library/FrameBufferBltLib/FrameBufferBltLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf
  LzmaDecompressLib|MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib.inf
  NetLib|NetworkPkg/Library/DxeNetLib/DxeNetLib.inf
  DpcLib|NetworkPkg/Library/DxeDpcLib/DxeDpcLib.inf
  UdpIoLib|NetworkPkg/Library/DxeUdpIoLib/DxeUdpIoLib.inf
  IpIoLib|NetworkPkg/Library/DxeIpIoLib/DxeIpIoLib.inf
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  PeCoffExtraActionLib|MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull.inf
  PeCoffLib|MdePkg/Library/BasePeCoffLib/BasePeCoffLib.inf
  PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
  PerformanceLib|MdePkg/Library/BasePerformanceLibNull/BasePerformanceLibNull.inf
  PrePiLib|EmbeddedPkg/Library/PrePiLib/PrePiLib.inf
  PrePiHobListPointerLib|ArmPlatformPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf
  PrePiMemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  OrderedCollectionLib|MdePkg/Library/BaseOrderedCollectionRedBlackTreeLib/BaseOrderedCollectionRedBlackTreeLib.inf
  RockchipPlatformLib|Rock5bPkg/Library/RockchipPlatformLib/RockchipPlatformLib.inf
  RockchipDisplayLib|Rockchip/Library/DisplayLib/RockchipDisplayLib.inf
  SafeIntLib|MdePkg/Library/BaseSafeIntLib/BaseSafeIntLib.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  SynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiRuntimeLib|MdePkg/Library/UefiRuntimeLib/UefiRuntimeLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
  UefiUsbLib|MdePkg/Library/UefiUsbLib/UefiUsbLib.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  TpmMeasurementLib|MdeModulePkg/Library/TpmMeasurementLibNull/TpmMeasurementLibNull.inf
  VarCheckLib|MdeModulePkg/Library/VarCheckLib/VarCheckLib.inf
  VariablePolicyLib|MdeModulePkg/Library/VariablePolicyLib/VariablePolicyLib.inf
  VariablePolicyHelperLib|MdeModulePkg/Library/VariablePolicyHelperLib/VariablePolicyHelperLib.inf
  TimeBaseLib|EmbeddedPkg/Library/TimeBaseLib/TimeBaseLib.inf

  SecureBootVariableLib|SecurityPkg/Library/SecureBootVariableLib/SecureBootVariableLib.inf
  SecureBootVariableProvisionLib|SecurityPkg/Library/SecureBootVariableProvisionLib/SecureBootVariableProvisionLib.inf

  # Platform Drivers
  SerialPortLib|Rockchip/Library/SerialPortLib/SerialPortLib.inf

  # System Reset
  HwResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf

  # PCIe
  PciSegmentLib|MdePkg/Library/BasePciSegmentLibPci/BasePciSegmentLibPci.inf
  PciHostBridgeLib|Rockchip/Library/PciHostBridgeLib/PciHostBridgeLib.inf
  PciExpressLib|Rockchip/Library/PciExpressLib/PciExpressLib.inf
  PciLib|MdePkg/Library/BasePciLibPciExpress/BasePciLibPciExpress.inf

  BaseBinSecurityLib|MdePkg/Library/BaseBinSecurityLibNull/BaseBinSecurityLibNull.inf
  DxeMemoryProtectionHobLib|MdeModulePkg/Library/MemoryProtectionHobLib/DxeMemoryProtectionHobLib.inf
  PcdDatabaseLoaderLib|MdeModulePkg/Library/PcdDatabaseLoaderLib/Dxe/PcdDatabaseLoaderLibDxe.inf
  RealTimeClockLib|EmbeddedPkg/Library/VirtualRealTimeClockLib/VirtualRealTimeClockLib.inf
  ResetUtilityLib|MdeModulePkg/Library/ResetUtilityLib/ResetUtilityLib.inf
  SecurityLockAuditLib|MdeModulePkg/Library/SecurityLockAuditDebugMessageLib/SecurityLockAuditDebugMessageLib.inf
  ResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf
  MemoryTypeInfoSecVarCheckLib|MdeModulePkg/Library/MemoryTypeInfoSecVarCheckLib/MemoryTypeInfoSecVarCheckLib.inf
  FltUsedLib|MdePkg/Library/FltUsedLib/FltUsedLib.inf
  MemoryTypeInformationChangeLib|MsCorePkg/Library/MemoryTypeInformationChangeLib/MemoryTypeInformationChangeLib.inf
  DtPlatformDtbLoaderLib|EmbeddedPkg/Library/DxeDtPlatformDtbLoaderLibDefault/DxeDtPlatformDtbLoaderLibDefault.inf
  VariableFlashInfoLib|MdeModulePkg/Library/BaseVariableFlashInfoLib/BaseVariableFlashInfoLib.inf
  PlatformPKProtectionLib|SecurityPkg/Library/PlatformPKProtectionLibVarPolicy/PlatformPKProtectionLibVarPolicy.inf

  MemoryInitPeiLib|ArmPlatformPkg/MemoryInitPei/MemoryInitPeiLib.inf

  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf
  CapsulePersistLib|MdeModulePkg/Library/CapsulePersistLibNull/CapsulePersistLibNull.inf      ## MU_CHANGE
  DebugAgentTimerLib|EmbeddedPkg/Library/DebugAgentTimerLibNull/DebugAgentTimerLibNull.inf
  DfciDeviceIdSupportLib|OemPkg/Library/DfciDeviceIdSupportLib/DfciDeviceIdSupportLib.inf
  DfciGroupLib|OemPkg/Library/DfciGroupLib/DfciGroups.inf
  DfciRecoveryLib|DfciPkg/Library/DfciRecoveryLib/DfciRecoveryLib.inf
  DfciSettingsLib|DfciPkg/Library/DfciSettingsLib/DfciSettingsLib.inf
  DfciUiSupportLib|OemPkg/Library/DfciUiSupportLib/DfciUiSupportLib.inf
  DfciV1SupportLib|DfciPkg/Library/DfciV1SupportLibNull/DfciV1SupportLibNull.inf
  DfciXmlDeviceIdSchemaSupportLib|DfciPkg/Library/DfciXmlDeviceIdSchemaSupportLib/DfciXmlDeviceIdSchemaSupportLib.inf
  DfciXmlIdentitySchemaSupportLib|DfciPkg/Library/DfciXmlIdentitySchemaSupportLib/DfciXmlIdentitySchemaSupportLib.inf
  DfciXmlPermissionSchemaSupportLib|DfciPkg/Library/DfciXmlPermissionSchemaSupportLib/DfciXmlPermissionSchemaSupportLib.inf
  DfciXmlSettingSchemaSupportLib|DfciPkg/Library/DfciXmlSettingSchemaSupportLib/DfciXmlSettingSchemaSupportLib.inf
  DfciSettingChangedNotificationLib|DfciPkg/Library/DfciSettingChangedNotificationLib/DfciSettingChangedNotificationLibNull.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  FmpAuthenticationLib|SecurityPkg/Library/FmpAuthenticationLibPkcs7/FmpAuthenticationLibPkcs7.inf
  HttpLib|NetworkPkg/Library/DxeHttpLib/DxeHttpLib.inf
  JsonLiteParserLib|MsCorePkg/Library/JsonLiteParser/JsonLiteParser.inf
  MsSecureBootModeSettingLib|OemPkg/Library/MsSecureBootModeSettingLib/MsSecureBootModeSettingLib.inf
  MuTelemetryHelperLib|MsWheaPkg/Library/MuTelemetryHelperLib/MuTelemetryHelperLib.inf
  NonDiscoverableDeviceRegistrationLib|MdeModulePkg/Library/NonDiscoverableDeviceRegistrationLib/NonDiscoverableDeviceRegistrationLib.inf
  OemHookStatusCodeLib|MdeModulePkg/Library/OemHookStatusCodeLibNull/OemHookStatusCodeLibNull.inf
  PasswordPolicyLib|OemPkg/Library/PasswordPolicyLib/PasswordPolicyLib.inf
  PlatformBootManagerLib|MsCorePkg/Library/PlatformBootManagerLib/PlatformBootManagerLib.inf
  SecureBootKeyStoreLib|OemPkg/Library/SecureBootKeyStoreLibOem/SecureBootKeyStoreLibOem.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  UefiDevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  UefiScsiLib|MdePkg/Library/UefiScsiLib/UefiScsiLib.inf
  ZeroTouchSettingsLib|ZeroTouchPkg/Library/ZeroTouchSettings/ZeroTouchSettings.inf
  MuSecureBootKeySelectorLib|MsCorePkg/Library/MuSecureBootKeySelectorLib/MuSecureBootKeySelectorLib.inf
  UpdateFacsHardwareSignatureLib|OemPkg/Library/UpdateFacsHardwareSignatureLib/UpdateFacsHardwareSignatureLib.inf
  FrameBufferMemDrawLib|MsGraphicsPkg/Library/FrameBufferMemDrawLib/FrameBufferMemDrawLib.inf
  LockBoxLib|MdeModulePkg/Library/LockBoxNullLib/LockBoxNullLib.inf
  AdvancedLoggerAccessLib|AdvLoggerPkg/Library/AdvancedLoggerAccessLib/AdvancedLoggerAccessLib.inf
  MemoryBinOverrideLib|MdeModulePkg/Library/MemoryBinOverrideLibNull/MemoryBinOverrideLibNull.inf

  TlsLib|CryptoPkg/Library/TlsLib/TlsLib.inf
  ConsoleMsgLib|PcBdsPkg/Library/ConsoleMsgLibNull/ConsoleMsgLibNull.inf
  DisplayUpdateProgressLib|MdeModulePkg/Library/DisplayUpdateProgressLibGraphics/DisplayUpdateProgressLibGraphics.inf

[LibraryClasses.common.SEC]
  ArmGicArchLib|ArmPkg/Library/ArmGicArchSecLib/ArmGicArchSecLib.inf
  ExtractGuidedSectionLib|EmbeddedPkg/Library/PrePiExtractGuidedSectionLib/PrePiExtractGuidedSectionLib.inf
  HobLib|EmbeddedPkg/Library/PrePiHobLib/PrePiHobLib.inf
  MemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PlatformPeiLib|ArmPlatformPkg/PlatformPei/PlatformPeiLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  PrePiLib|EmbeddedPkg/Library/PrePiLib/PrePiLib.inf
  PrePiMemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PrePiHobListPointerLib|ArmPlatformPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf

[LibraryClasses.common.DXE_CORE]
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  HobLib|MdePkg/Library/DxeCoreHobLib/DxeCoreHobLib.inf
  MemoryAllocationLib|MdeModulePkg/Library/DxeCoreMemoryAllocationLib/DxeCoreMemoryAllocationLib.inf
  DxeCoreEntryPoint|MdePkg/Library/DxeCoreEntryPoint/DxeCoreEntryPoint.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf
  PerformanceLib|MdeModulePkg/Library/DxeCorePerformanceLib/DxeCorePerformanceLib.inf

[LibraryClasses.common.DXE_DRIVER]
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  SecurityManagementLib|MdeModulePkg/Library/DxeSecurityManagementLib/DxeSecurityManagementLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf

[LibraryClasses.common.UEFI_APPLICATION]
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiTianoCustomDecompressLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf

[LibraryClasses.common.UEFI_DRIVER]
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiTianoCustomDecompressLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  UefiScsiLib|MdePkg/Library/UefiScsiLib/UefiScsiLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf

[LibraryClasses.common.DXE_RUNTIME_DRIVER]
  RockchipPlatformLib|Rock5bPkg/Library/RockchipPlatformLib/RockchipPlatformLib.inf
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  ArmHvcLib|ArmPkg/Library/ArmHvcLib/ArmHvcLib.inf
  ArmSmcLib|ArmPkg/Library/ArmSmcLib/ArmSmcLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf

  # System Reset
  HwResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf

  VariablePolicyLib|MdeModulePkg/Library/VariablePolicyLib/VariablePolicyLibRuntimeDxe.inf

  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/RuntimeCryptLib.inf

[Components.common]
  #
  # PEI Phase modules
  #
  ArmPlatformPkg/PrePi/PeiUniCore.inf
  MdeModulePkg/Core/Pei/PeiMain.inf
  MdeModulePkg/Universal/PCD/Pei/Pcd.inf {
    <LibraryClasses>
    PcdDatabaseLoaderLib|MdeModulePkg/Library/PcdDatabaseLoaderLib/Pei/PcdDatabaseLoaderLibPei.inf
  }

  #
  # DXE
  #
  MdeModulePkg/Core/Dxe/DxeMain.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/DxeCrc32GuidedSectionExtractLib/DxeCrc32GuidedSectionExtractLib.inf
  }
  #
  # Architectural Protocols
  #
  ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf {
  <LibraryClasses>
    RealTimeClockLib|EmbeddedPkg/Library/VirtualRealTimeClockLib/VirtualRealTimeClockLib.inf
  }
  MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf

  #
  # PCIe
  #
#  Rockchip/Drivers/PciPlatform/PcieInitDxe.inf
#  ArmPkg/Drivers/ArmPciCpuIo2Dxe/ArmPciCpuIo2Dxe.inf
#  MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
#  MdeModulePkg/Bus/Pci/PciHostBridgeDxe/PciHostBridgeDxe.inf
#  MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf
#  # MdeModulePkg/Bus/Pci/NvmExpressPei/NvmExpressPei.inf
#  # MdeModulePkg/Bus/Pci/EhciDxe/XhciDxe.inf
#  MdeModulePkg/Bus/Ata/AtaAtapiPassThru/AtaAtapiPassThru.inf
#  MdeModulePkg/Bus/Pci/SataControllerDxe/SataControllerDxe.inf
#
#  MdeModulePkg/Bus/Pci/NonDiscoverablePciDeviceDxe/NonDiscoverablePciDeviceDxe.inf
#  # MdeModulePkg/Bus/Pci/EhciDxe/EhciDxe.inf


  MdeModulePkg/Universal/FaultTolerantWriteDxe/FaultTolerantWriteDxe.inf
  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

  #
  # Display
  #
  Rockchip/Drivers/Vop2Dxe/Vop2Dxe.inf
  #Rockchip/Library/DisplayLib/AnalogixDpLib.inf
  Rockchip/Library/DisplayLib/DwHdmiQpLib.inf
  Rockchip/Drivers/LcdGraphicsOutputDxe/LcdGraphicsOutputDxe.inf

  #
  # BGRT
  #
 #Rock5bPkg/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf
  MdeModulePkg/Universal/Acpi/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf

  # Processor Core Services
  ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
  ArmPkg/Drivers/ArmPsciMpServicesDxe/ArmPsciMpServicesDxe.inf
  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf

  # Runtime Services
  MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf

  # Fake Variable Services
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

  # Security Stub
  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

#  SecurityPkg/VariableAuthenticated/SecureBootConfigDxe/SecureBootConfigDxe.inf

  MsCorePkg/MuVarPolicyFoundationDxe/MuVarPolicyFoundationDxe.inf

  # BDS
  MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  MdeModulePkg/Universal/SerialDxe/SerialDxe.inf
  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
  MdeModulePkg/Universal/DriverHealthManagerDxe/DriverHealthManagerDxe.inf
  MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  # HID Support
  HidPkg/HidKeyboardDxe/HidKeyboardDxe.inf
  HidPkg/HidMouseAbsolutePointerDxe/HidMouseAbsolutePointerDxe.inf

  # Disk IO
  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf
  FatPkg/EnhancedFatDxe/Fat.inf
  MdeModulePkg/Bus/Scsi/ScsiBusDxe/ScsiBusDxe.inf
  MdeModulePkg/Bus/Scsi/ScsiDiskDxe/ScsiDiskDxe.inf

  # USB
  EmbeddedPkg/Drivers/VirtualKeyboardDxe/VirtualKeyboardDxe.inf

  # ACPI and SMBIOS
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
  Rock5bPkg/AcpiTables/AcpiTables.inf

  # DTB
  EmbeddedPkg/Drivers/DtPlatformDxe/DtPlatformDxe.inf {
  <LibraryClasses>
    DtPlatformDtbLoaderLib|EmbeddedPkg/Library/DxeDtPlatformDtbLoaderLibDefault/DxeDtPlatformDtbLoaderLibDefault.inf
  }

  MdeModulePkg/Universal/Acpi/AcpiPlatformDxe/AcpiPlatformDxe.inf
  MdeModulePkg/Universal/Acpi/FirmwarePerformanceDataTableDxe/FirmwarePerformanceDxe.inf

  # Pci
  MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
  MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf

  # Gpio
  Rock5bPkg/RK3588GpioDxe/RK3588GpioDxe.inf

  # RK806
  Rock5bPkg/RK3588Dxe/RK3588Dxe.inf

  # I2C drivers
  Rockchip/Drivers/I2c/I2cDxe/I2cDxe.inf
  MdeModulePkg/Bus/I2c/I2cDxe/I2cDxe.inf
  Rockchip/Drivers/I2c/I2cDemoDxe/I2cDemoDxe.inf
  Rockchip/Applications/I2cDemoTest/I2cDemoTest.inf

  # MMC/SD
# EmbeddedPkg/Universal/MmcDxe/MmcDxe.inf
# Synopsys/DesignWare/Drivers/DwEmmcDxe/DwEmmcDxe.inf
# Rockchip/Drivers/MmcDxe/MmcDxe.inf
# Rockchip/Drivers/DwEmmcDxe/DwEmmcDxe.inf
# Rockchip/Drivers/SdhciHostDxe/SdhciHostDxe.inf

  # NOR FLASH
  Rockchip/Drivers/NorFlashDxe/NorFlashDxe.inf
  Rockchip/Drivers/NorFlashDxe/RkFvbDxe.inf
  Rockchip/Applications/SpiTool/SpiFlashCmd.inf

  # AHCI Support
  Rockchip/Drivers/SataControllerDxe/SataControllerDxe.inf
  Rockchip/Drivers/AtaAtapiPassThru/AtaAtapiPassThru.inf
  MdeModulePkg/Bus/Ata/AtaBusDxe/AtaBusDxe.inf

  #
  # SMBIOS Support
  #
  Rock5bPkg/PlatformSmbiosDxe/PlatformSmbiosDxe.inf
  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf

  #
  # USB Ohci Controller
  #
  Rockchip/Drivers/OhciDxe/OhciDxe.inf

  #
  # USB Ehci Controller
  #
  Rockchip/Drivers/EhciDxe/EhciDxe.inf

  #
  # USB Dwc3 Controller
  #
  Rockchip/Drivers/UsbDwc3InitDxe/UsbDwc3.inf

  #
  # USB Xhci Controller
  #
  Rockchip/Drivers/XhciDxe/XhciDxe.inf

  #
  # USB Host Support
  #
  MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf

  #
  # USB Mass Storage Support
  #
  MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  #
  # USB Kb Support
  #
  MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf

  #
  # USB Mouse Support
  #
  MdeModulePkg/Bus/Usb/UsbMouseDxe/UsbMouseDxe.inf

  #
  # USB MouseAbsolutePointer Support
  #
  MdeModulePkg/Bus/Usb/UsbMouseAbsolutePointerDxe/UsbMouseAbsolutePointerDxe.inf

  #
  # USB Peripheral Support
  #
  EmbeddedPkg/Drivers/AndroidFastbootTransportUsbDxe/FastbootTransportUsbDxe.inf

  #
  # Fastboot
  #
  EmbeddedPkg/Application/AndroidFastboot/AndroidFastbootApp.inf

  #
  # Android Boot applications
  #
  EmbeddedPkg/Application/AndroidBoot/AndroidBootApp.inf

  #
  # UEFI Network Stack
  #
!include NetworkPkg/Network.dsc.inc
  #
  # AX88772 Ethernet Driver
  #
  ASIX/Bus/Usb/UsbNetworking/Ax88772c/Ax88772c.inf

  # Bds
  MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf {
    <LibraryClasses>
      PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  }
#  MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
#  MdeModulePkg/Application/UiApp/UiApp.inf {
#    <LibraryClasses>
#      NULL|MdeModulePkg/Library/DeviceManagerUiLib/DeviceManagerUiLib.inf
#      NULL|MdeModulePkg/Library/BootManagerUiLib/BootManagerUiLib.inf
#      NULL|MdeModulePkg/Library/BootMaintenanceManagerUiLib/BootMaintenanceManagerUiLib.inf
#      PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
#  }
  ShellPkg/Application/Shell/Shell.inf {
    <LibraryClasses>
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|Rockchip/Applications/I2cDemoTest/I2cDemoTest.inf
      NULL|Rockchip/Applications/SpiTool/SpiFlashCmd.inf
      #NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      OrderedCollectionLib|MdePkg/Library/BaseOrderedCollectionRedBlackTreeLib/BaseOrderedCollectionRedBlackTreeLib.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf
    <PcdsFixedAtBuild>
      gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
      gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|8000
  }

!ifdef $(INCLUDE_TFTP_COMMAND)
  ShellPkg/DynamicCommand/TftpDynamicCommand/TftpDynamicCommand.inf
!endif #$(INCLUDE_TFTP_COMMAND)

   MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
   MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
   EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
   MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
   MdeModulePkg/Universal/EsrtFmpDxe/EsrtFmpDxe.inf

   AdvLoggerPkg/AdvancedFileLogger/AdvancedFileLogger.inf
   MdeModulePkg/Universal/MemoryTest/NullMemoryTestDxe/NullMemoryTestDxe.inf

   CryptoPkg/Driver/CryptoDxe.inf

