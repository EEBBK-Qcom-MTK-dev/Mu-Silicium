INF QcomPkg/XBLCore/XBLCore.inf

FILE FREEFORM = DDE58710-41CD-4306-DBFB-3FA90BB1D2DD {
    SECTION UI = "uefiplat.cfg"
    SECTION RAW = RawFiles/uefiplat.cfg
}

INF MdeModulePkg/Core/Dxe/DxeMain.inf
INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
INF QcomPkg/Drivers/SecurityDxe/SecurityDxe.inf
INF QcomPkg/Drivers/SecRSADxe/SecRSADxe.inf
INF QcomPkg/Drivers/ASN1X509Dxe/ASN1X509Dxe.inf
INF QcomPkg/Drivers/VerifiedBootDxe/VerifiedBootDxe.inf
INF QcomPkg/Drivers/TzDxe/TzDxeLA.inf
INF QcomPkg/Drivers/MdtpDxe/MdtpDxe.inf
INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
INF MdeModulePkg/Universal/Variable/EmuRuntimeDxe/EmuVariableRuntimeDxe.inf
INF QcomPkg/Drivers/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
INF QcomPkg/Drivers/SimpleTextInOutSerialDxe/SimpleTextInOutSerial.inf
INF QcomPkg/Drivers/ResetRuntimeDxe/ResetRuntimeDxe.inf
INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
INF QcomPkg/Drivers/FontDxe/FontDxe.inf
INF QcomPkg/Drivers/EnvDxe/EnvDxe.inf
INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
INF QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
INF QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
INF QcomPkg/Drivers/SmemDxe/SmemDxe.inf
INF QcomPkg/Drivers/ULogDxe/ULogDxe.inf
INF QcomPkg/Drivers/NpaDxe/NpaDxe.inf
INF QcomPkg/Drivers/DiskIoDxe/DiskIoDxe.inf
INF QcomPkg/Drivers/PartitionDxe/PartitionDxe.inf
INF FatPkg/EnhancedFatDxe/Fat.inf
INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
INF MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf
INF QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
INF QcomPkg/Drivers/ClockDxe/ClockDxe.inf
INF QcomPkg/Drivers/HWIODxe/HWIODxe.inf
INF QcomPkg/Drivers/I2CDxe/I2CDxe.inf
INF QcomPkg/Drivers/SPIDxe/SPIDxe.inf
INF QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
INF QcomPkg/Drivers/SdccDxe/SdccDxe.inf
INF QcomPkg/Drivers/UFSDxe/UFSDxe.inf
INF QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
INF QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
INF QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
INF QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
INF QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
INF QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
INF QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
INF QcomPkg/Drivers/AdcDxe/AdcDxe.inf
INF QcomPkg/Drivers/TsensDxe/TsensDxe.inf
INF QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
INF QcomPkg/Drivers/MpPowerDxe/MpPowerDxe.inf
INF QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
INF QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
INF QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
INF QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
INF QcomPkg/Drivers/HashDxe/HashDxe.inf
INF QcomPkg/Drivers/RNGDxe/RngDxe.inf
INF QcomPkg/Drivers/QcomBds/QcomBds.inf
INF QcomPkg/Drivers/QdssDxe/QdssDxe.inf
INF QcomPkg/Application/QcomChargerApp/QcomChargerApp.inf
INF QcomPkg/Application/OppoDL/OppoDlAPP.inf

FILE FREEFORM = A91D838E-A5FA-4138-825D-455E2303079E {
    SECTION UI = "BDS_Menu.cfg"
    SECTION RAW = RawFiles/BDS_Menu.cfg
}


FILE FREEFORM = A91D838E-A5FA-4138-825D-455E23030794 {
    SECTION UI = "logo1.bmp"
    SECTION RAW = RawFiles/logo1.bmp
}


FILE FREEFORM = 3E5584ED-05D4-4267-9048-0D47F76F4248 {
    SECTION UI = "boot_charger_low_battery3.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery3.bmp
}


FILE FREEFORM = C360A1F2-25AA-456F-AE75-20701550B4E3 {
    SECTION UI = "boot_charger_low_battery3_new.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery3_new.bmp
}


FILE FREEFORM = 75EF0A68-E7D3-4D31-B42E-40FCE992A283 {
    SECTION UI = "boot_charger_poc_new.bmp"
    SECTION RAW = RawFiles/boot_charger_poc_new.bmp
}


FILE FREEFORM = 935843C4-05BD-11E8-BA89-0ED5F89F718B {
    SECTION UI = "boot_charger_poc_new1.bmp"
    SECTION RAW = RawFiles/boot_charger_poc_new1.bmp
}


FILE FREEFORM = 74B07DA0-3B6D-460A-9927-320FB9EA4D10 {
    SECTION UI = "boot_charger_low_battery_new.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery_new.bmp
}


FILE FREEFORM = 83E861CE-E89E-4998-8958-B087A3520098 {
    SECTION UI = "boot_charger_low_battery2_new.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery2_new.bmp
}


FILE FREEFORM = 4753E815-DDD8-402D-BF69-9B8C4EB7573E {
    SECTION UI = "battery_symbol_NoBattery.bmp"
    SECTION RAW = RawFiles/battery_symbol_NoBattery.bmp
}


FILE FREEFORM = 03DED53E-BECD-428F-9F79-5ABA64C58445 {
    SECTION UI = "boot_charger_poc.bmp"
    SECTION RAW = RawFiles/boot_charger_poc.bmp
}


FILE FREEFORM = 8B86CD38-C772-4FCF-85AA-345B2B3C1AB4 {
    SECTION UI = "boot_charger_low_battery.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery.bmp
}


FILE FREEFORM = 3FD97907-93F1-4349-AF3C-3B68B0A5E626 {
    SECTION UI = "boot_charger_low_battery2.bmp"
    SECTION RAW = RawFiles/boot_charger_low_battery2.bmp
}


FILE FREEFORM = E2EA5A4F-98BD-4203-AB49-399505DDFB7D {
    SECTION UI = "tsens_thermal_symbol.bmp"
    SECTION RAW = RawFiles/tsens_thermal_symbol.bmp
}


FILE FREEFORM = C72FB1A9-5527-4E13-BAC4-F671D0330145 {
    SECTION UI = "tsens_thermal_err_symbol.bmp"
    SECTION RAW = RawFiles/tsens_thermal_err_symbol.bmp
}


FILE FREEFORM = A1E235DE-E825-4591-9623-C43175811826 {
    SECTION UI = "SecParti.cfg"
    SECTION RAW = RawFiles/SecParti.cfg
}


FILE FREEFORM = F12A1F3D-4318-A006-5F7F-3FAAF6DBB4B5 {
    SECTION UI = "tracer_event.cfg"
    SECTION RAW = RawFiles/tracer_event.cfg
}


FILE FREEFORM = 45FE4B7C-150C-45DA-A021-4BEB2048EC6F {
    SECTION UI = "QcomChargerCfg.cfg"
    SECTION RAW = RawFiles/QcomChargerCfg.cfg
}


FILE FREEFORM = F780C779-DD7C-47CD-BD1A-5EB414C51704 {
    SECTION UI = "BATTERY.PROVISION"
    SECTION RAW = RawFiles/BATTERY.PROVISION
}


FILE FREEFORM = 44E7BB0B-12EA-43E0-A16A-7FAD77131E21 {
    SECTION UI = "verifyboot.bmp"
    SECTION RAW = RawFiles/verifyboot.bmp
}

