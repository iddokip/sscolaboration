#!/bin/python3
import random
randd = random.randint(1,100)
attempts = 0

while attempts  < 8 :
    u_input = input("guess number between 1 and 100 : ")
    if u_input.isdigit():
        u_input = int(u_input)
        if u_input > randd:
            print("Ypu guessed too high")
        elif u_input < randd:
            print("You guessed too low")
        else:
            print(" your attemps {} congratulations you guessed right {}:".format(attempts, randd))
            break
        attempts += 1
    print("WRONG INPUT")
print("No more attempts {} the number was {} :".format(attempts, randd))

    





