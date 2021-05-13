import os.path
def CheckFile():
    stringVmFiles=["C:\\WINDOWS\\system32\\vm3dgl64.dll",
		  "C:\\WINDOWS\\system32\\vm3dgl.dll",
		"C:\\WINDOWS\\system32\\vm3dum64.dll",
		"C:\\WINDOWS\\system32\\vm3dum.dll",
		"C:\\WINDOWS\\system32\\VmbuxCoinstaller.dll",
		"C:\\WINDOWS\\system32\\vmGuestLib.dll",
		"C:\\WINDOWS\\system32\\vmGuestLibJava.dll",
		"C:\\WINDOWS\\system32\\vmhgfs.dll",
		"C:\\WINDOWS\\system32\\vmwogl32.dll",
		"C:\\WINDOWS\\system32\\vmmreg32.dll",
		"C:\\WINDOWS\\system32\\vmx_fb.dll",
		"C:\\WINDOWS\\system32\\vmx_mode.dll",
		"C:\\WINDOWS\\system32\\VMUpgradeAtShutdownWXP.dll"]
    for i in stringVmFiles:
        FileExit=os.path.exists(i)
        if FileExit:
            flag=FileExit
            print("suspious file detected: "+i)
    if flag:
        pass
    else:
        print("There was no suspicious file")