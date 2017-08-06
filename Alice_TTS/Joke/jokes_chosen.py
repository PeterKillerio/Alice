import pyttsx3
import jokes_listread

from random import randint

def choose_say():
    jokes_index = randint(0, len(jokes_listread.jokes_list) - 1)
    chosen_joke = jokes_listread.jokes_list[jokes_index]

    engine = pyttsx3.init()
    engine.say(chosen_joke)
    print("Alice: "+ chosen_joke)
    engine.runAndWait()
