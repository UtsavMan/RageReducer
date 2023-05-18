import serial
import time
import cv2
import keyboard
import ctypes


arduinoSerialData = serial.Serial('COM3',9600)
arduinoSerialData.timeout = 1
zeroHealth = False

while True:
    thing = arduinoSerialData.inWaiting()>0
    if(thing):
        myData = arduinoSerialData.readline().decode("ascii");
        if(int(myData) == 20040707):
            cam_port = 0
            cam = cv2.VideoCapture(cam_port)
            result, image = cam.read();
            
            cv2.imwrite("WEBCAMTEST.png", image)
            time.sleep(1)
            keyboard.send("alt+F4")
            time.sleep(5)
            ctypes.windll.user32.SystemParametersInfoW(20, 0, "C:/Users/Utsav/WEBCAMTEST.png", 0)
            break



