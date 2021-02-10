import mypkg
import os
os.system("python -m pip install psutil")
os.system("python -m pip install pywin32")
mypkg.activewindow.CheckWindow()
mypkg.computername.CheckComputerName()
mypkg.core.CheckCore()
mypkg.disksize.CheckDisksize()
mypkg.file.CheckFile()
mypkg.macadress.CheckMacAdress()
mypkg.memory.CheckMemory()
mypkg.process.CheckProcess()
mypkg.registry.CheckRegistry()
