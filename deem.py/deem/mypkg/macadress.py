import uuid, re
def CheckMacAdress():
    macadress='-'.join(re.split('(..)', format(uuid.getnode(), 'x'))[1::2])
    print("MacAdress: "+macadress)