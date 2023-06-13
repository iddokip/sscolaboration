#!/bin/python3
import random
import math
oneto9 = list(range(6))
for i in oneto9:
    print("{} : {} ".format(oneto9.index(i), i))
randlist = ["string","name","kuku"]
randlist1 = randlist + oneto9
randlist1.append("appended")
print(randlist1)
for i in randlist[:3]:
    print("{} , {}".format(randlist1.index(i),i))
randlist1[0] = "first string"
print("first changed ", randlist1)

emptylist = []
for i in range(5):
    emptylist.append(random.randrange(5,60))
    print("{}".format(emptylist[i], end=""))
