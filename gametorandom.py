#!/bin/python3
import random

def play_game():
    randd = random.randint(1, 100)
    attempts = 0
    score = None

    while attempts < 5:
        u_input = input("Input a number between 1 and 100: ")
        rem = 4 - attempts

        if u_input.isdigit():
            u_input = int(u_input)
            if u_input > randd:
                print("Too HIGH. {} attempts remaining.".format(rem))
            elif u_input < randd:
                print("Too LOW. {} attempts remaining.".format(rem))
            else:
                score = attempts
                print("Your attempt was: {}. Congratulations, you guessed right! The number was {}.".format(attempts, randd))
                break
        else:
            print("Invalid input. Please enter a valid number between 1 and 100. {} attempts remaining.".format(rem))

        attempts += 1

    if attempts == 5 and score is None:
        print("No more attempts. The number was {}.".format(randd))
    elif score is not None:
        print("Your score is: {}".format(score))

    return score

def play_again():
    play_game()
    play_again = input("Do you want to play again? (yes/no): ")
    if play_again.lower() == "yes":
        play_again()

print("Random number generated between 1 and 100.")
play_again()
