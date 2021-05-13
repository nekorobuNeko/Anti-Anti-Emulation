import psutil
flag=False
def CheckProcess():
    PROCNAME = ["sample.exe", "sub.exe"]
    for proc in psutil.process_iter():
        for a in PROCNAME: 
            if proc.name() == a:
                global flag
                flag=True
                print("suspicious process detected:"+a)
    if flag:
        pass
    else:
        print("could not detect suspicious process")