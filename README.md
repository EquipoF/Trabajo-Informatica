# Trabajo-Informatica

  ## Lista de estilos
  - Clases: la primera letra en mayúscula, el resto minúscula. Si hay varias palabras, se escriben todas juntas y se delimitan poniendo su primera letra en mayúsculas.
  ```
  //Ejemplo:
  class MiClase
  {
  ...
  };
 ```
  - Métodos: (igual que clases)
  ```
  //Ejemplo:
  void MiClase::Metodo();
  void MiClase::SegundoMetodo(int parametro);
 ```
  - Variables: todas las leteras en minúscula. Si hay varias palabras, se escriben todas juntas y se delimitan poniendo su primera letra en mayúsculas.
  ```
  //Ejemplo:
  int entero;
  float numComaFlotante;
  unsigned char caracterSinSigno;
 ```
  - Objetos: (igual que las variables) + si hay un solo objeto de una clase, se le llama igual que esta.
  ```
  //Ejemplo:
  MiClase miClase;
  OtraClase objetoUno, objetoDos;
 ```
  - Defines: todas sus letras en mayúsculas. Si hay varias palabras, se separan mediante "_"
  ```
  //Ejemplo:
  #define GRAVEDAD -9.81f
  #define DIFERENCIAL_TIEMPO 0.025f
 ```
  - Enum: (igual que defines)
  ```
  //Ejemplo:
  enum { CERO = 0, PRIMER_OBJETO = 1 };
 ```
  - Variables de métodos set: las variables propias del set se llaman igual que las primera palabra del atributo que setea añadiendo "In" al final. 
  ```
  //Ejemplo:
  void MiClalse::SetVel(float vIn){
    vMiClase = vIn;
  }
 ```
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
   Tres opciones de cámara:
   - Subiendo a ritmo constante 
   - Subiendo por tramos según avanza el personaje estilo [Jump King](https://www.youtube.com/watch?v=ktVhJ41AExU)
   - Moverse con el personaje
   ### Posibles muertes (Game Over)
   - Por objetos que quitan vida (trampas)
   - Si la cámara se mueve con el personaje: poner un nivel de “lava” que pueda matar si caes en él.     
   - Si la cámara avanza constante: salirte fuera de la pantalla.
   - Si la cámara avanza por cachos: perder vida por caída.
   ### Controles:
   - [X] movimiento básico *tipo* WASD (Izquierda, derecha, salto, agacharse) 
   - [ ] Caer más despacio si estás pegado a la pared.
   ### Poderes/habilidades/bonus
   - [X] Doble salto _(pulsar tecla de salto 2 veces)_
   - [X] Salto cargado _(agacharse + salto tipo [Jump King](https://www.youtube.com/watch?v=ktVhJ41AExU))_
   - [X] salto de pared _(Interacción::choque(personaje,caja) == true && botón de salto)_
   - [ ] Dash _(pulsar tecla de mvto. dos veces o tecla + shift)_
   - [ ] El nivel sube mas lento 
   - [ ] Escudo contra cosas que dañan
   - [ ] etc...
    
## Objetivos (corto plazo)
- [X] Crear nuevo proyecto
- [X] Incluir las clases Vector2D, ObjetoMovil
- [X] Incluir el Main
- [X] Crear una nueva clase Pared o Plataforma y sus métodos (como dibujar en paralelo a la pantalla)
- [X] Crear clase hombre (con hitbox cuadrada)
- [X] Crear clase interacción (interaccion::colision(*Hombre, *Pared)...)
- [X] Añadir controles onKeyboardUp() 

## Objetivos (medio plazo)
- [ ] Terminar la generación del mundo
- [ ] Terminar movimiento del personaje y colisiones
- [ ] Sistema de puntuación (items, contador...)
- [ ] Menú de inicio y final de partida (máquina de estados)
- [ ] Guardar puntuación (ficheros)
- [ ] Ampliar contenido: power ups 
- [ ] Ampiar contenido: distintas plataformas (trampas)
- [ ] Ampiar contenido: bolas de cañon
- [ ] Niveles en ficheros
- [ ] Último: texturas y estética
- [ ] Revisar formato del código
