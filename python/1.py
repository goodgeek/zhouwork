#! /usr/bin/python

import threading
import time

lock = threading.Lock()

def showMessage(name):
    lock.acquire()
    print("hello thread", threading.currentThread().name)
    lock.release()

t1 = threading.Thread(target=showMessage, args=("hello",))
t1.start()
t1.join()
