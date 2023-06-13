#!/bin/python3
amount, intrest = input("enter amount and intrest : ").split();
amount = float(amount)
intrest = float(intrest) * .01
for i in range(10):
    amount = amount + (amount * intrest)
print(f"{amount:.2f} :The amount after 10 years")
