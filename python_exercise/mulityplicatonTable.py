#!/bin/python3
import math
row = [ [0] * 10 for i in  range(10)]

for i in range(10):
    for j in range(10):
        #print(f"{i} * {j}", end=" | ")
        row[i][j] = i * j
for i  in range(10):
    if i > 0 and j > 0:
        for j in range(10):
            if j > 0:
                if row[i][j] < 10:
                    print(" ", end="")
                else:
                    print(end="")
            print(row[i][j], end=" | ") 
        print()

