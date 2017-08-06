import pyttsx3
from random import randint
closing_phrase_file = 'Closing_phrase/closing.txt'


closing_phrase_cont = open(closing_phrase_file, 'r')

closing_phrase_list = []

for line in closing_phrase_cont:
    closing_phrase_list.append(line)

def tell_closing():
    closing_phrase_index = randint(0, len(closing_phrase_list) - 1)
    closing_phrase = closing_phrase_list[closing_phrase_index]
    engine = pyttsx3.init()

    engine.say(closing_phrase)
    print("Alice: "+ closing_phrase)
    engine.runAndWait()