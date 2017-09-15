import pyttsx3
import datetime

engine = pyttsx3.init()
rate = engine.getProperty('rate')
engine.setProperty('rate', rate-60)

while 1:
        data = datetime.datetime.now().time()
        hours = data.hour
        minutes = data.minute

        wordHours = ""
        wordMinutes = ""

        if (hours > 12):
                wordHours = "PM"
        elif (hours < 12):
                wordHours = "AM"
        else:
                wordHours = "O'clock"

        if (minutes > 1):
                wordMinutes = "minutes"
        else:
                wordMinutes = "minute"

        engine.say("It-is" + str(hours)+ " " + wordHours)
        engine.runAndWait()

        engine.say("It-is" + str(hours)+ " " + str(minutes) + wordMinutes + " " + wordHours)
        engine.runAndWait()

        break
