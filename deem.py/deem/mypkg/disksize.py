import psutil
def CheckDisksize():
    # ディスクサイズを取得
    dsk = psutil.disk_usage('/')
    # Gbで表示
    disksize=dsk.total/1024/1024/1024;
    if disksize<60:
        print("Disksize is smaller than 60Gb")
    else:
        print("There was no problem with the disksize")