APRIORI DXE {
        INF MdeModulePkg/Core/Dxe/DxeMain.inf
        INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
        INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
        INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
        INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
        INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
        INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
        INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf 
        INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
        INF ArmPkg/Drivers/ArmPsciMpServicesDxe/ArmPsciMpServicesDxe.inf

        INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
        INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
        INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
        INF MdeModulePkg/Universal/SerialDxe/SerialDxe.inf

        # RockChip Drivers
        INF Rock5bPkg/RK3588GpioDxe/RK3588GpioDxe.inf
        INF Rockchip/Drivers/I2c/I2cDxe/I2cDxe.inf
        INF Rockchip/Drivers/Vop2Dxe/Vop2Dxe.inf
        INF Rockchip/Library/DisplayLib/DwHdmiQpLib.inf
        INF Rockchip/Drivers/LcdGraphicsOutputDxe/LcdGraphicsOutputDxe.inf
        INF MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
        INF Rockchip/Drivers/UsbDwc3InitDxe/UsbDwc3.inf
        INF NetworkPkg/DpcDxe/DpcDxe.inf
        INF Rockchip/Drivers/NorFlashDxe/NorFlashDxe.inf
        INF Rockchip/Drivers/NorFlashDxe/RkFvbDxe.inf
        INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
        INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
        INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
        INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
        INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
        INF EmbeddedPkg/Drivers/DtPlatformDxe/DtPlatformDxe.inf
#        INF Rock5bPkg/LogoDxe/LogoDxe.inf
        INF Rock5bPkg/RK3588Dxe/RK3588Dxe.inf
        
        # RK806 Pmic
        INF Rock5bPkg/PlatformSmbiosDxe/PlatformSmbiosDxe.inf
        INF MdeModulePkg/Universal/FaultTolerantWriteDxe/FaultTolerantWriteDxe.inf
        INF MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
        INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
        INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
        INF Rockchip/Drivers/EhciDxe/EhciDxe.inf
        INF Rockchip/Drivers/OhciDxe/OhciDxe.inf
#        INF MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
#        INF MsGraphicsPkg/DisplayEngineDxe/DisplayEngineDxe.inf
        INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
        INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
        INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
        INF MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf
        INF MdeModulePkg/Bus/I2c/I2cDxe/I2cDxe.inf
        INF EmbeddedPkg/Drivers/VirtualKeyboardDxe/VirtualKeyboardDxe.inf
        INF MdeModulePkg/Universal/Acpi/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf
        INF Rockchip/Drivers/XhciDxe/XhciDxe.inf
        INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
        INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf
        INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
        INF MdeModulePkg/Bus/Usb/UsbMouseDxe/UsbMouseDxe.inf
        INF MdeModulePkg/Bus/Usb/UsbMouseAbsolutePointerDxe/UsbMouseAbsolutePointerDxe.inf
        INF EmbeddedPkg/Drivers/AndroidFastbootTransportUsbDxe/FastbootTransportUsbDxe.inf
        INF NetworkPkg/MnpDxe/MnpDxe.inf
        INF NetworkPkg/ArpDxe/ArpDxe.inf
        INF NetworkPkg/Dhcp4Dxe/Dhcp4Dxe.inf
        INF NetworkPkg/Ip4Dxe/Ip4Dxe.inf
        INF NetworkPkg/Udp4Dxe/Udp4Dxe.inf
        INF NetworkPkg/Mtftp4Dxe/Mtftp4Dxe.inf
        INF NetworkPkg/TcpDxe/TcpDxe.inf
        INF NetworkPkg/UefiPxeBcDxe/UefiPxeBcDxe.inf
        INF ASIX/Bus/Usb/UsbNetworking/Ax88772c/Ax88772c.inf
        INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
        INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
        INF FatPkg/EnhancedFatDxe/Fat.inf
        INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
        INF Rockchip/Drivers/SataControllerDxe/SataControllerDxe.inf
        INF Rockchip/Drivers/AtaAtapiPassThru/AtaAtapiPassThru.inf
        INF MdeModulePkg/Bus/Ata/AtaBusDxe/AtaBusDxe.inf
        INF AdvLoggerPkg/AdvancedFileLogger/AdvancedFileLogger.inf
        INF MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
        INF MdeModulePkg/Universal/EsrtFmpDxe/EsrtFmpDxe.inf
        INF CryptoPkg/Driver/CryptoDxe.inf
        INF MdeModulePkg/Universal/Acpi/FirmwarePerformanceDataTableDxe/FirmwarePerformanceDxe.inf
        INF MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf
        INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
        INF MsGraphicsPkg/GopOverrideDxe/GopOverrideDxe.inf
        INF MsCorePkg/MuCryptoDxe/MuCryptoDxe.inf
        INF MsGraphicsPkg/MsUiTheme/Dxe/MsUiThemeProtocol.inf
        INF MsGraphicsPkg/RenderingEngineDxe/RenderingEngineDxe.inf
        INF MdeModulePkg/Universal/BootManagerPolicyDxe/BootManagerPolicyDxe.inf
        INF MdeModulePkg/Universal/RegularExpressionDxe/RegularExpressionDxe.inf
        INF MsWheaPkg/HwErrBert/HwErrBert.inf
        INF MsWheaPkg/MsWheaReport/Dxe/MsWheaReportDxe.inf
        INF MsWheaPkg/HwhMenu/HwhMenu.inf
# Error
        INF MdeModulePkg/Universal/Acpi/AcpiPlatformDxe/AcpiPlatformDxe.inf
# Error
        INF MsCorePkg/AcpiRGRT/AcpiRgrt.inf
        INF OemPkg/BootMenu/BootMenu.inf
        INF DfciPkg/SettingsManager/SettingsManagerDxe.inf
        INF MsGraphicsPkg/SimpleWindowManagerDxe/SimpleWindowManagerDxe.inf
# Error
        INF MsGraphicsPkg/MsEarlyGraphics/Dxe/MsEarlyGraphics.inf 
# Error
        INF MsGraphicsPkg/OnScreenKeyboardDxe/OnScreenKeyboardDxe.inf 
        INF DfciPkg/IdentityAndAuthManager/IdentityAndAuthManagerDxe.inf
}
