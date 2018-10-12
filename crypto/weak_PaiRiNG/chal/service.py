import threading
import socket
import sys
import os
import json

host = "0.0.0.0"
port = 40010

tcpsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpsock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

tcpsock.bind((host,port))
threads = []

with open("signatures.json") as f:
    valid_signatures = json.load(f)

class ClientThread(threading.Thread):

    def __init__(self,ip,port,socket):
        threading.Thread.__init__(self)
        self.ip = ip
        self.port = port
        self.socket = socket
        print "[+] New thread started for "+ip+":"+str(port)

    def run(self):
        welcome="""
Hello there! We the watchers of the firewall only allow admins to pass!
To gain access you must either be admin or join the blackhat!

To be authenticated, you must sign a special message with one of the admin private keys.
The message to sign: I am become admin, the owner of this server

The server uses RSA digital signature protocol according to PKCS#1 v1.5.
Use SHA-1 to first hash the message before signing.

Submit the base64 encoded version of the signed message as passphrase.

"""

        self.socket.send(welcome)
        self.socket.send("Enter Passphrase:")

        data = self.socket.recv(1024).strip('\n')

        if data in valid_signatures:
            self.socket.send("\nHello admin! ECTF{gcd_15_50_E45y_70_C4LCUl47e}")

        else:
            self.socket.send("\nSorry, invalid passphrase. Be admin or be gone!")
        
        self.socket.close()
        return



while True:
    tcpsock.listen(4)
    print "\nListening for incoming connections..."
    (clientsock, (ip, port)) = tcpsock.accept()

    # Let's use a new thread for each incoming connection
    newthread = ClientThread(ip, port, clientsock)
    newthread.start()
    threads.append(newthread)

for t in threads:
    t.join()
