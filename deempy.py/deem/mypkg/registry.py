import winreg
def CheckRegistry():
    pathname = ["SOFTWARE\\Clients\\StartMenuInternet\\VMWAREHOSTOPEN.EXE",
		"SOFTWARE\\VMware, Inc.\\VMware Tools",
		"SOFTWARE\\Microsoft\\ESENT\\Process\\vmtoolsd",
		"SYSTEM\\CurrentControlSet\\Enum\\IDE\\CdRomNECVMWar_VMware_SATA_CD01_______________1.00____",
		"SYSTEM\\CurrentControlSet\\Enum\\IDE\\CdRomNECVMWar_VMware_IDE_CDR10_______________1.00____",
		"SYSTEM\\CurrentControlSet\\Enum\\SCSI\\Disk&Ven_VMware_&Prod_VMware_Virtual_S&Rev_1.0",
		"SYSTEM\\CurrentControlSet\\Enum\\SCSI\\Disk&Ven_VMware_&Prod_VMware_Virtual_S",
		"SYSTEM\\CurrentControlSet\\Control\\CriticalDeviceDatabase\\root#vmwvmcihostdev",
		"SYSTEM\\CurrentControlSet\\Control\\VirtualDeviceDrivers",
		"SYSTEM\\CurrentControlSet\\Services\\IRIS5",
		"SOFTWARE\\eEye Digital Security",
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Wireshark",
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\wireshark.exe",
		"SOFTWARE\\ZxSniffer.exe",
		"SOFTWARE\\Cygwin",
		"SOFTWARE\\B Labs\\Bopup Observer",
		"AppEvents\\Schemes\\Apps\\Bopup Observer",
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Win Sniffer_is1",
		"SOFTWARE\\Win Sniffer"]
    for path in pathname:
        try:
            key = winreg.OpenKeyEx(winreg.HKEY_CURRENT_USER, path)
            print("suspicious register: "+path)
        except FileNotFoundError:
            pass
    try:
        winreg.CloseKey(key)
    except NameError:
        print("could not detect suspicious register")
