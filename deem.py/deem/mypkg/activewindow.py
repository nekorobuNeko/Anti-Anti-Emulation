#解析に使用される仮想環境ではアクティブウィンドウが常にデスクトップになっていることがあるためそれを探索
from win32gui import GetWindowText, GetForegroundWindow,GetDesktopWindow
def CheckWindow():
    ForegroundWindow=GetForegroundWindow()
    DesktopWindow=GetDesktopWindow()
    if  ForegroundWindow==DesktopWindow:
        print("ForegroundWindow is Desktop")
    else:
        print("There was no problem with the Foregroundwindows ")