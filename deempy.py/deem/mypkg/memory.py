import os
import psutil
def CheckMemory():
    mem = psutil.virtual_memory().total/1024/1024/1024
    if mem<4:
        print("memory size is smaller than 4Gb")
    else:
        print("There was no problem with the memory")