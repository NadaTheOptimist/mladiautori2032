import serial

ser = serial.Serial()
ser.baudrate = 9600     #baud rate
ser.port = "COM5"       #serial port
ser.timeout = 3         #sekundi koliko će program čekati odgovor
ser.open()              #otvori serial port

ser.write("PIN01 HIGH".encode())
waitForResponse(False)