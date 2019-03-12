import serial, time
arduino = serial.Serial('/dev/cu.usbmodem1421', 115200, timeout=1)
time.sleep(3) #give the connection a second to settle
arduino.write("hell3o i6ts s;hane>")
