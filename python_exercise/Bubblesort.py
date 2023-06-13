#!/bin/python3
import random
randomlist = []
for i in range(5):
    randomlist.append(random.randrange(5,60))
print(randomlist)
i = len(randomlist)
while i > 1:
    for j in range(len(randomlist) - 1):
        print("is {} greater that {}".format(randomlist[j],randomlist[j+1]))
        if randomlist[j] > randomlist[j+1]:
            print("swapping")
            print()
            tmp = randomlist[j]
            randomlist[j] = randomlist[j +1]
            randomlist[j +1] = tmp
            print(randomlist)
        else:
            print("DONT SWAPP")
            print()
    i -= 1
    print("END OF LOOP")
    print()
for k in randomlist:
    print(k, end=", ")
print()
print("**********USING sort()*************")
randomlist.sort()
for k in randomlist:
    print(k, end=", ")
print()
print("**********USING reverse()*************")
randomlist.reverse()
for k in randomlist:
    print(k, end=", ")
print()
print("**********USING insert()*************")
randomlist.insert(0 ,"inserted")
randomlist.insert(1 , "toberemoved")
for k in randomlist:
    print(k, end=", ")
print()
print("**********USING pop()*************")
randomlist.pop(0)
for k in randomlist:
    print(k, end=", ")
print()
print("**********USING remove()*************")
randomlist.remove("toberemoved")
for k in randomlist:
        print(k, end=", ")
print()






print("********** multiply each value by 3 *************")
randomlist = [i * 3 for i in range(10)]
for k in randomlist:
    print(k, end=", ")
print()
