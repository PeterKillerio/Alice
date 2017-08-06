import pyttsx3
from Hello import hello_chosen

def name():
    engine = pyttsx3.init()

    engine.say("My name is Alice. Whats your name?")

    print("Alice: My name is Alice. Whats your name?")
    engine.runAndWait()
    name = input("Enter your name: ")
    print()
    greeting_sentence = "Alice: " + hello_chosen.greeting_modified + " " + name + "."
    print(greeting_sentence)
    engine = pyttsx3.init()
    voice_sentence = hello_chosen.greeting_modified + name
    engine.say(voice_sentence)
    engine.runAndWait()