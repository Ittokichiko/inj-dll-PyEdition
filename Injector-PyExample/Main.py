import ctypes as ct
from os import _exit as ex_function
import psutil
def main():
    input_dllname = input("Please Write You're DLL Name(you need also with full name of folder for working my script!!!): ")
    procname = input("You're Process Name: ")
    injector = ct.WinDLL("injector.dll")
    for proc in psutil.process_iter(['pid', 'name']):
        if proc.info['name'] == procname:
            pid = proc.info['pid']
            if injector.Inject(pid, bytes("{}".format(input_dllname), "utf-8")) == True:
                print("Injected!!!")
                ex_function(322)
            else:
                print("Failed to Inject {}".format(input_dllname))
                ex_function(300)
        else:
            raise Exception("Not Founded {}".format(proc.info['name']))

if __name__ == "__main__":
    main()    
