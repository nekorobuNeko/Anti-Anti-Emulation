import socket
def CheckComputerName():
    host = socket.gethostname()
    l=[ "USER", "ANDY", "COMPUTERNAME", "CUCKOO", "SANDBOX", "NMSDBOX",
		"XXXX-OX", "CWSX", "WILBERT-SC", "XPAMAST-SC"]
    for i in l:
        if host==i:
            print("suspicious computer name: "+i)
            break
    print("unsuspicious computer name: "+host)

