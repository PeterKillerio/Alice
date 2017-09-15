import numpy as np
import cv2
from math import floor

import pyautogui

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

xMedian = 0
yMedian = 0
substractX = 0
substractY = 0

control = 0

font = cv2.FONT_HERSHEY_SIMPLEX

#def oneaxis(id, axis, value):
    #time.sleep(0.05)
   # ##pyautogui.typewrite(str(id)+" "+str(axisOne)+str(value))
   # time.sleep(0.05)
  #  ##pyautogui.press('enter')

def twoaxis(id, axisOne, valueOne, axisTwo, valueTwo):
    text = (str(id)+" "+str(axisOne)+str(valueOne)+" "+str(axisTwo)+str(valueTwo))
    pyautogui.typewrite(str(id)+" "+str(axisOne)+str(valueOne)+" "+str(axisTwo)+str(valueTwo))
    pyautogui.press('enter')

#pyautogui.keyDown('alt')
#pyautogui.press('tab')      
#pyautogui.keyUp('alt')

while True:
    ret, img = cap.read()

   
    edges = cv2.Canny(img, 80, 180)



    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

   #cv2.putText(img,'X',(320, 240), font, 1,(0,0,0),cv2.LINE_AA)

    cv2.circle(img, (320, 240), 100, (50,50,255), 3)

    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]

       

        substractX = 320 - (x+floor(w/2))
        substractY = 240 - (y+floor(h/2))

        wrajtX1 = 320 
        wrajtY1 = 240
        
        wrajtX2 = 320 + (320 - (x+floor(w/2)))
        wrajtY2 = 240 + (240 - (y+floor(h/2)))

        cv2.line(img, (320,240),(wrajtX2,wrajtY2),(20,205,220), 12)

    if (control == 2):
    

        if ((( 50 < substractX) or (substractX < -50))or ((  50 < substractY) or (substractY < -50))):

            pohybX = float(substractX/520) #320
            pohybY = float(substractY/520) 

            pohybY = float("{0:.2f}".format(pohybY))
            pohybX = float("{0:.2f}".format(pohybX))


            twoaxis("G91 G0", "X",  pohybX, "Y", pohybY)
            
        control = 0

    substractX = 0
    substractY = 0

    control = control + 1


    cv2.imshow('img',img)
    cv2.imshow('gray',gray)
    cv2.imshow('edges',edges)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()