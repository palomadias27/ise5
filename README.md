## Especificaciones

Hacer un programa en `micropython` que permita medir aceleracion y cambios de angulo en los tres ejes (X, Y, Z). Debe haber dos LED RGB (uno para el acelerometro y otro para el giroscopo) que den combinacoines de colores de acuerdo a los valores que indique el `MPU6050`. Las combinaciones son:

<div align="center">
  
| LED 1 | Eje X | Eje Y | Eje Z | 
| ----- | ----- | ----- | ----- |  
| Apagado |  (+)  |  (+)  |  (+)  |
| Azul |  (+)  |  (+)  |  (-)  |
| Verde |  (+)  |  (-)  |  (+)  |
| Cian |  (+)  |  (-)  |  (-)  |
| Rojo |  (-)  |  (+)  |  (+)  |
| Violeta |  (-)  |  (+)  |  (-)  |
| Verde |  (-)  |  (-)  |  (+)  |
| Blanco |  (-)  |  (-)  |  (-)  |
  
</div>

Se debe imprimir periodicamente los valores del MPU por el interprete de Micropython con este formato:

```
Aceleracion X: valor g
Aceleracion Y: valor g
Aceleracion Z: valor g

Variacion angular X: valor grados/s
Variacion angular Y: valor grados/s
Variacion angular Z: valor grados/s
```

Luego, hacer un `README.md` con lo siguiente:

```markdown
# Micropython - MPU6050

Alumno: Nombre y apellido
Curso: Curso
Materia: Adquisición de Datos

[link del proyecto de wokwi del .txt]
```

## Consideraciones

- Documentación de [micropython](http://docs.micropython.org/en/latest/). Van a tener que usar la clase `I2C` del modulo `machine`. Particularmente, hay un apartado para la `Raspberry Pi Pico` en [Quick reference for the RP2](http://docs.micropython.org/en/latest/rp2/quickref.html#pins-and-gpio).
- El simulador para que usen es [Wokwi](https://wokwi.com/arduino/new?template=micropython-pi-pico).
- Documentación del [simulador](https://docs.wokwi.com/micropython) que van a usar.
- Lista de componentes:
  - Raspberry Pi Pico.
  - 2 LEDs RGB.
  - 6 resistencias de 330 o 220.
  - MPU6050
- El modulo para el `MPU6050` lo pueden ver en el repo, fue sacado de este [link](https://microcontrollerslab.com/micropython-mpu-6050-esp32-esp8266/). Solo copien el contenido del `mpu6050.py` en un nuevo archivo en Wokwi.
- El calculo de las unidades lo pueden deducir de la pagina 25 de la [hoja de datos](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) del `MPU6050`. En este momento esta calibrado a ±2g y ±250 grados/s a fondo de escala con 16 bits de resolucion de ADC.

## Como entregar

- Archivos para subir: `main.py`, `diagram.json`, `wokwi-project.txt` y el `README.md`.
- Nombre de la rama: `ise5/2021/upython/mpu6050`.
