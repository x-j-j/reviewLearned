#!/usr/bin/python3
import logging
logging.getLogger("scapy.runtime").setLevel(logging.ERROR)
from scapy.all import *
import sys

if len(sys.argv) != 2:
    print("you need one para")
    sys.exit()
ip = sys.argv[1]
answer = sr1(IP(dst=str(ip))/ICMP(), timeout=1, verbose=0)
if answer == None:
    print("no response")
elif int(answer[IP].ttl) <= 64:
    print("Host is Linux/Win7/Win95")
else:
    print("Host is Win2000/UNINX")


#  1、WINDOWS NT/2000   TTL：128
#  2、WINDOWS 95/98     TTL：32
#  3、UNIX              TTL：255
#  4、LINUX             TTL：64
#  5、WIN7              TTL：64
