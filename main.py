from machine import ADC, Pin
import utime
from math import log
sensor_temp = machine.ADC(27)
pote_temp = machine.ADC(26)
conversion_factor = 3.3 / (65535)
B1 = Pin(8, Pin.OUT)
L1 = Pin(4, Pin.OUT)
L2 = Pin(7, Pin.OUT)

T0 = 298
r = 10000
B = 3950

while True:
  Reads = sensor_temp.read_u16() * conversion_factor
  Rn = ((Reads*r)/(3.3-Reads))
  Tk = ((T0*B)/(T0*log(Rn/r)+B))
  Readp = pote_temp.read_u16() * conversion_factor
  Tp = (Readp*35)/3.3
  Tc = Tk - 273
  if (Tp < Tc):
    L1.on()
    L2.off()
    B1.off()
  if (Tp > Tc):
    L1.off()
    L2.on()
    B1.on()
  print("Temperatura del sensor {:.2f}".format(Tc))
  print("Temperatura del potenciometro {:.2f}".format(Tp))
  utime.sleep(2)