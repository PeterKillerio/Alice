import pyttsx3


from Hello import name_voice
from Joke import jokes_chosen
from Before_joke import before_joke
from Closing_phrase import closing_voice
from To_do_phrase import to_do_phrase

from playsound import playsound
playsound('Sounds/dial.mp3')

engine = pyttsx3.init()
rate = engine.getProperty('rate')
engine.setProperty('rate', rate-20)

name_voice.name()



while(42 == 42):

    to_do_phrase.tell_to_do()

    print("Available commands: 'tell a joke','end'")



    command = input("Enter your command: ")

    if command == "tell a joke":
        before_joke.tell_phrase()
        jokes_chosen.choose_say()
    elif command == "end":
        closing_voice.tell_closing()
        playsound('Sounds/shut.mp3')
        break
    else:

        print("Alice: You should learn to write sooner than to code.")
        engine.say("You should learn to write sooner than to code.")
        engine.runAndWait()



