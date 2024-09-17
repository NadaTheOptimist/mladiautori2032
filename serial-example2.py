import serial

ser = serial.Serial()
ser.baudrate = 9600     #baud rate
ser.port = "/dev/ttyUSB3"       #serial port
ser.timeout = 3         #sekundi koliko će program čekati odgovor
ser.open()              #otvori serial port

while True:
  poruka = ser.readline()
  poruka = poruka.decode("utf-8")
  print(poruka, end = "")
