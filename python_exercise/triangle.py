#!/bin/python3
h = input("height : ")
h = int(h)
s = h - 1
hashh = 1
for i in range(h):
    for j in range(s):
        print(" " ,end="")
    for k in range(hashh):
        print("#", end="")
    print()
    s = s - 1
    hashh = hashh + 2

