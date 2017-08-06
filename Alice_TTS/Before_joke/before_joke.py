from random import randint
import pyttsx3

before_joke_file = 'Before_joke/before_joke.txt'


before_joke_cont = open(before_joke_file, 'r')

before_joke_list = []

for line in before_joke_cont:
    before_joke_list.append(line)

def tell_phrase():
    before_joke_index = randint(0, len(before_joke_list) - 1)
    before_joke_phrase = before_joke_list[before_joke_index]
    engine = pyttsx3.init()

    engine.say(before_joke_phrase)
    print("Alice: "+before_joke_phrase)
    engine.runAndWait()
