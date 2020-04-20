# Trabajo-Informatica

  ## Lista de estilos
  - Clases: La primera letra en mayúscula, el resto minúscula. Si hay varias palabras se separan con "_" y todas sus letras van en minúscula.
  - Obejtos:Todas las leteras en minúscula. Si hay varias palabras, se escriben todas juntas y se delimitan poniendo su primera letra en mayúsculas.
  - Defines: Todas sus letras en mayúsculas. si hay varias palabras, se separan mediante "_"
  - Métodos set: las variables propias del set se llaman igual que los atributos que setean pero añadiendo la palabra "In" al final.
  - Abreviaturas:
    - Derecha: Dcha
    - Izquierda: Izq

  ## Características
   ### Género
   - Juego de plataformas vertical.
   - Sin enemigos.
   - Meter monedas en sitios complicados.
   - Poner trampas, pinchos, cañones, etc. que te maten.
   ### Cámara     
   Dos opciones de cámara:
   - Que vaya subiendo a ritmo constante 
   - Que vaya subiendo por cachos según subes estilo [Jump King](https://www.youtube.com/watch?v=ktVhJ41AExU)
   ### Posibles muertes (Game Over)
   - Con las cosas que te quitan vida.
   - Si la cámara es fija en el personaje: poner un nivel de “lava” que te pueda matar.     
   - Si la cámara avanza constante: salirte fuera de la pantalla.
   - Si la cámara avanza por cachos: perder vida por caída.
   ### Controles:
   - movimiento básico *tipo* WASD (Izquierda, derecha, salto, agacharse) 
   - Caer más despacio si estás pegado a la pared.
   ### Poderes/habilidades/bonus
   - Doble salto _(pulsar tecla de salto 2 veces)_
   - Salto cargado _(agacharse + salto tipo [Jump King](https://www.youtube.com/watch?v=ktVhJ41AExU))_
   - dash _(pulsar tecla de mvto. dos veces o tecla + shift)_
   - salto de pared _(Interacción::choque(personaje,caja) == true && botón de salto)_
   - que el nivel suba mas lento 
   - escudo para cosas que te matan
   - etc...
    
## Objetivos (corto plazo)
- [X] Crear nuevo proyecto
- [X] Incluir las clases Vector2D, ObjetoMovil
- [X] Incluir el Main
- [X] Crear una nueva clase Pared o Plataforma y sus métodos (como dibujar en paralelo a la pantalla)
- [X] Crear clase hombre (con hitbox cuadrada)
- [ ] Crear clase interacción (interaccion::colision(*Hombre, *Pared)...)
- [ ] Añadir controles onKeyboardUp() 
