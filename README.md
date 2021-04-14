# LM35

El trabajo que van a tener que hacer esta en el `main.cpp`. El resto de los archivos estan para facilitarles la tarea.

## Consigna

- El algoritmo que desarrollen tiene que ser capaz de mostrar la temperatura que indique el LM35 en un LCD con dos decimales de precisión.
- El programa debe mostrar las temperaturas en un rango de -55 a 150 grados con la mayor exactitud posible.

## Orientación

- Pueden mirar esta [página](https://trq20.github.io/guides/libraries) para entender mejor como funcionan las librerías y que funciones pueden usar.
- Recuerden que el valor que reciban de la función `analogRead` es un número entero que es proporcional a la temperatura, pero necesita que le hagan una conversión. Pueden pensarlo así:

```c
uint16_t val = analogRead(0);		          // Devuelve un numero entre 0 y 1023
float tension = (float)val * REF / 1023;	// Valor de tension que en el pin
float temp = tension * 100;               // Valor de temperatura que mide el LM35
```

Esto puede hacerse de forma mas compacta, pero la idea es que tenemos que hacer la lectura, luego convertirla a tensión con la relación de la segunda linea (donde `REF` es el valor de tensión de referencia que elegimos). Este paso es indistinto para el sensor que estemos usando, mientras que el último paso es convertir el valor de tensión que entrega el sensor a la magnitud que nos interesa (en este caso temperatura) y ahí dependeremos de como se comporte cada sensor. En nuestro caso, esa cuenta sale de pensar:

<img style="display: block; margin-left: auto; margin-right: auto;" src="https://render.githubusercontent.com/render/math?math=V_{out} = 10 \frac{mV}{C} \space x \space T\space[C]">

<img style="display: block; margin-left: auto; margin-right: auto;" src="https://render.githubusercontent.com/render/math?math=T\space[C] = \frac{V_{out}}{10\frac{mV}{C}} = 100\space x \space V_{out}">

- Recuerden que pueden fijar una tensión de referencia mas apropiada para mejorar la precisión de la medición si arman un divisor de tensión y conectan esa tensión al pin `AREF` del microcontrolador.

## Circuito y simulación

Los componentes que van a necesitar mínimamente son:
- ATmega328P.
- Diodo 1N914 x 2.
- LM35.
- Resistencia de 18K.
- LCD 16x2 (aparece en la librería de Proteus con el nombre LM016L).

Son libres de decidir que pines del microcontrolador usar. Algunas aclaraciones:

- Sobre el LCD:
  - `VDD` y `VEE` van a `5V`.
  - `VSS` y `RW` van a `GND`.
  - `D0-D3` no se conectan.
  - `RS`, `E`, `D4-D7` van al microcontrolador en el orden que prefieran.
- El LM35 tiene que estar configurado como en el primer apartado.
- Recuerden que los pines analógicos son `PC0-PC6`.
- Los pines `AVCC` y `RESET` del microcontrolador deben ir a `5V`.

Una vez que tengan el circuito armado y el programa compilado, tienen que hacer doble click en el microcontrolador o click derecho y propiedades y en *Program file* cargar el `.hex` que obtuvieron al compilar. Una vez que esto lo tengan, simulan el circuito dando inicio con el botón que está en la esquina inferior izquierda.

## Como probar el código

Una vez que terminen el programa, vayan a la terminal, asegúrense de que esta apunte a la carpeta donde están trabajando y escriban `make -f makefile.mk`. Si todo está en orden, tienen que ver este mensaje:

```
$ make -f makefile.mk
avr-gcc -Wall -g -Os -mmcu=atmega328p -DF_CPU=1000000 -I. -o lm35.bin main.cpp libs/analog.cpp libs/LCD.cpp
avr-objcopy -j .text -j .data -O ihex lm35.bin lm35.hex
```

Y luego, van a ver que algunos archivos nuevos van a aparecer, uno de ellos es el `lm35.hex`, este contiene la traducción de nuestro código a instrucciones en hexadecimal que vamos a grabar en la flash del microcontrolador.

En el Proteus, vayan a las propiedades del microcontrolador y en *Program file* carguen el `lm35.hex`. Luego den inicio a la simulación con el botón en la esquina inferior izquierda.

## Como entregar

Van a tener que entregar solo el `main.cpp` y un `README.md` con lo siguiente:

```markdown
# LM35

Alumno: Nombre y Apellido
Curso: Curso
Materia: Adquisición de Datos

[Imagen del circuito]
```

Luego, pongan el `README.md`, el `main.cpp` y la imagen del circuito (llamémosle `img.png`) en una carpeta y corran en una terminal:

```
git init
git add README.md main.cpp img.png
git commit -m "Initial commit"
git checkout -b ise5/2021/temperatura/lm35
git push https://github.com/trq20/USERNAME.git ise5/2021/temperatura/lm35
```

Recuerden de cambiar `USERNAME` por su nombre de usuario en GitHub. Pueden verificar si la entrega se hizo visitando la rama del repositorio en `https://github.com/trq20/USERNAME/tree/ise5/2021/temperatura/lm35`.
