import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1421',115200, timeout = 1)
def write(ser):
    time.sleep(5)
    ser.write('a')


def readarduino(ser):
    did=True
    while ser.inWaiting(): # Check number of characters left in buffer
        if did and ser.inWaiting() < 490: # Select last 500 characters in buffer
            for i in range(6):
                print ser.readline() # Print 6 lines in buffer
            did = False
        ser.readline()  # Clear buffer line by line until ser.inWaiting

readarduino(ser)
write(ser)
readarduino(ser)
print("done");






#ser = serial.Serial('/dev/ttyACM')  # open serial port
#print(ser.name)         # check which port was really used
#ser.write(b'hello')     # write a string
#ser.close()
