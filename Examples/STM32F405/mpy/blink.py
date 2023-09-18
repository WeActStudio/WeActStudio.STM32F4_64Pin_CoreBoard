from pyb import LED
from time import sleep
from pyb import Switch

sw = Switch()
led = LED(1) # 1=blue

while True:
    led.toggle()
    if sw.value():
        sleep(0.2)
    else:
        sleep(1)
