## Especificaciones

Hacer un programa en `micropython` que sirva de sistema de alerta cada vez que la temperatura indicada por un `NTC` sea superior a una de referencia. Cuando esto ocurre, un buzzer y un LED rojo deben encenderse. De lo contrario, un LED azul debe estar encendido.
Luego, hacer un `README.md` con lo siguiente:

```markdown
# Micropython - Alarma

Alumno: Nombre y apellido
Curso: Curso
Materia: Adquisición de Datos
```

## Consideraciones

- Documentación de [micropython](http://docs.micropython.org/en/latest/). Van a tener que usar la clase `ADC` del modulo `machine`. Particularmente, hay un apartado para la `Raspberry Pi Pico` en [Quick reference for the RP2](http://docs.micropython.org/en/latest/rp2/quickref.html#pins-and-gpio).
- El simulador para que usen es [Wokwi](https://wokwi.com/arduino/new?template=micropython-pi-pico).
- Documentación del [simulador](https://docs.wokwi.com/micropython) que van a usar.
- Lista de componentes:
  - Raspberry Pi Pico.
  - 2 LEDs.
  - 2 resistencias de 330 o 220.
  - NTC.
  - Buzzer.
  - Potenciómetro.
- Para referencia, el potenciómetro en su mayor valor de resistencia debe indicar una temperatura de 35 grados.
- La fórmula para calcular lal temperatura del NTC es:

<div align="center">
  <img src="https://render.githubusercontent.com/render/math?math=T_{(R)} = \frac{\beta T_0}{T_0 ln \Big(\frac{R_{(T)}}{R_{(T_0)}}\Big ) %2B \beta}">
</div>

Con `β = 3950`, `T0 = 298`, `R(T0) = 10K`. 

## Como entregar

- Archivos para subir: `main.py`, `diagram.json`, `wokwi-project.txt` y el `README.md`.
- Nombre de la rama: `ise5/2021/upython/alarma`.
