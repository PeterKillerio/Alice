import pyttsx3
from random import randint
to_do_file = 'To_do_phrase/to_do.txt'


to_do_cont = open(to_do_file, 'r')

to_do_list = []

for line in to_do_cont:
    to_do_list.append(line)

def tell_to_do():
    to_do_index = randint(0, len(to_do_list) - 1)
    to_do_phrase = to_do_list[to_do_index]
    engine = pyttsx3.init()

    engine.say(to_do_phrase)
    print("Alice: "+ to_do_phrase)
    engine.runAndWait()