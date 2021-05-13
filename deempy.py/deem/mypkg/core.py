import multiprocessing
def CheckCore():
    a=multiprocessing.cpu_count()
    if a<=2:
        print("core number is 2 or less")
    else:
        print("There was no problem with the core")