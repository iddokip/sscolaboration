#!/bin/python3
a = 5
print(f"original a = {a}")
b = 10
print(f"original b = {b}")
temp = a
a = b 
b = temp
print("a was {} and now is {}".format(b,a))
