import serial

ser = serial.Serial()
ser.baudrate = 9600     #baud rate
ser.port = "/dev/ttyUSB3"       #serial port
ser.timeout = 3         #sekundi koliko će program čekati odgovor
ser.open()              #otvori serial port

ser.write("\n  hello vidi-x!".encode())
