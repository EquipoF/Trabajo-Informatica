#include "Personaje.h"
#include "Interaccion.h"

//Parámetros del cuerpo
#define ALTO 1.0f
#define ANCHO 0.5f
#define GRAVEDAD -10.0f

#define COS_45 1/1.414f
#define SEN_45 1/1.414f

#define accx 10.0f //6//Aceleración para el eje X
#define velxLim 5.0f //Velocidad límite del eje x

//Nombres de las teclas
enum { DCHA = 'd', IZQ = 'a', ABAJO = 's', ESPACIO = ' ', ESPACIO_SOLTADO = 0, DCHA_SOLTADO = 1, IZQ_SOLTADO = 2, ABAJO_SOLTADO=3 };

//Tipos de salto
enum { NORMAL = 0, PARED_DCHA = 1, PARED_IZQ = 2, SALTO_ABAJO = 4, CARGADO = 3 };

//Tipos de dash
enum { DASH_DCHA = 1, DASH_IZQ = 2, DASH_ABAJO = 3 };
 
Personaje::Personaje(): sprite("imagenes/rana.png", 11), sprite_salto("imagenes/rana_salto.png"), sprite_caida("imagenes/caer.png")
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
	aceleracion.y = GRAVEDAD;
	vMov = 3.0;//1.0;
	vSalto = 7.0;
	multiplicadorCargado = 2.0f;
	saltosRestantes = 2; //nº de saltos para probar

	//variables de contacto para probar los saltos de pared
	contactoParedDcha = false;
	contactoParedIzq = false;

	//inicializacion posiciones y tamaños sprites
	Vector2D centro = Vector2D(0.5, 0.5);
	Vector2D size = Vector2D(1, 1.3);

	sprite.setCenter(centro.x, centro.y);
	sprite.setSize(size.x, size.y);

	sprite_salto.setCenter(centro.x, centro.y);
	sprite_salto.setSize(size.x, size.y);

	sprite_caida.setCenter(centro.x, centro.y);
	sprite_caida.setSize(size.x, size.y);
	//altura = 1.8f;
}
Personaje::~Personaje()
{
}
/*
void Personaje::SetAcc(Vector2D acclIn) 
{
	//Código aqúi
	Vector2D velAux;

	//
	ObjetoMovil::SetVel(velAux);
}
void Personaje::SetAcc(float accxIn, float accyIn) 
{
	Personaje::SetVel(Vector2D(accxIn, accyIn));
}
*/
void Personaje::setvMov(float vIn) 
{
	vMov = vIn;
}
void Personaje::setvSalto(float vIn) 
{
	vSalto = vIn;
}
void Personaje::setSaltosRes(int saltosIn)
{
	saltosRestantes = saltosIn;
}
int Personaje::getSaltosRes(void)
{
	return saltosRestantes;
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);

	//gestion de direccion y animacion

	if (velocidad.x > 0.01)sprite.flip(false, false);//sprite idle
	if (velocidad.x < -0.01)sprite.flip(true, false);
	

	if (velocidad.x > 0.01)sprite_salto.flip(false, false);//sprite salto
	if (velocidad.x < -0.01)sprite_salto.flip(true, false);
	

	if (velocidad.x > 0.01)sprite_caida.flip(false, false);//sprite caida
	if (velocidad.x < -0.01)sprite_caida.flip(true, false);
	

	if (velocidad.y > 0.01)
		sprite_salto.draw();
	else if(velocidad.y < -0.01)
		sprite_caida.draw();
	else if (velocidad.y < 0.01 && velocidad.y > -0.1f)
	{
		sprite.draw();
		sprite.loop();
	}
		
	glPopMatrix();
	
	//cuerpo.Dibuja(); //dibujar para ver la hitbox
}

void Personaje::Inicializa()
{
	Personaje::SetPos(0.0f, -2.0f);
	Personaje::SetVel(0.0, 0.0);
	Personaje::SetAcc(0.0, GRAVEDAD);
	dchaPresionado = false;
	izqPresionado = false;
	plataformaEnContacto = -1; //No está en contacto con nada
}

void Personaje::Mueve(float t, ListaRectangulos& plataformas, Caja& caja) 
{
	ObjetoMovil::Mueve(t);
	//Parche BUG#? (el de no seguir avanzando cuando te chocas con algo y subes)
	if (dchaPresionado) {
		velocidad.x = vMov;
		aceleracion.x = accx;
	}
	if (izqPresionado) {
		velocidad.x = -vMov;
		aceleracion.x = -accx;
	}

	//Corrección de velocidad
	if(velocidad.x >0 && velocidad.x > velxLim)
	{
		velocidad.x = velxLim;
	} 
	else if (velocidad.x < 0 && velocidad.x < -velxLim)	{
		velocidad.x = -velxLim;
	}

	//Corrección de posición
	int aux = Interaccion::Choque(plataformas, *this); //Evaluar si hay choque con plataforma y guarda el resultado en aux
	if (aux != -1) // Si hay choque con alguna plataforma
	{
		//Guardo aux en un atributo del personaje para que no se pierda al repetir la operación pero con la posición corregida
		plataformaEnContacto = aux;
	}
	if (plataformaEnContacto != -1)
	{
		if (Interaccion::SalidaLateral(plataformas, *this)) {
			int asdf = 0;
		}
	}

	Interaccion::Choque(caja, *this);

	//Gravedad OFF por colisión
	//Te sales de una plataforma

	//Cambiar posición para dibujar
	cuerpo.setCentro(posicion);	
}
void Personaje::Tecla(unsigned char key) 
{   // ¿Separar este método de la ejecucuón de movimientos (que solo procese los flags de las teclas) => hacer Personaje::Accion para llamar a los saltos y cambiar las velocidades de X?
	//Flags para la detección de teclas.
	static bool espacioPresionado = false;	//Hago un booleano que perdura en el timepo para guardar el estado de las teclas
	static bool abajoPresionado = false;

	switch (key) //Llevar el tratamiento de las teclas (flags y eso) al main
	{
	//Movimiento derecha
	case DCHA:
		//velocidad.x = vMov;
		//aceleracion.x = accx;
		dchaPresionado = true;
		break;

	case DCHA_SOLTADO:
		dchaPresionado = false;
		break;

	//Movimiento izquierda
	case IZQ:
		izqPresionado = true;
		break;

	case IZQ_SOLTADO:
		izqPresionado = false;
		break;
	
	//Movimiento vertical
	case ABAJO:
		abajoPresionado = true;
		break;

	case ABAJO_SOLTADO:
		abajoPresionado = false;
		break;

	//Se presiona la barra espaciadora => se solicita un salto
	case ESPACIO:
		//Meter aquí los distintos tipos de salto.
 		if (!espacioPresionado) //Si no estaba pulsada antes, es decir, la acabo de pulsar, genero un salto
		{
			if (contactoParedDcha && dchaPresionado) { //Salto de pared
				Personaje::Salta(PARED_DCHA);
			}
			else if (contactoParedIzq && izqPresionado) { //Salto de pared
				Personaje::Salta(PARED_IZQ);
			}
			else if (velocidad.modulo() == 0 && abajoPresionado) { //Si estás quieto y presionas abajo + salto (se puede añadir una espera)
				Personaje::Salta(CARGADO);
			}
			else {	//Salto normal
				Personaje::Salta(NORMAL);
			}
		}
		espacioPresionado = true; //Marco la barra espaciadora como pulsada.
		break;
	//Se suelta la barra espaciadora
	case ESPACIO_SOLTADO:
		espacioPresionado = false; //la marco como no pulsada.
		break;
	}
	if (!dchaPresionado && !izqPresionado) //Parche para el BUG#1
	{
		//si estás en el suelo para, sino no
		velocidad.x = 0.0;
		aceleracion.x = 0.0f;
	}
}

void Personaje::Salta(unsigned int tipoSalto) {
	//Gravedad ON
	aceleracion.y = GRAVEDAD;
	//Comprobaciones para saltar
	switch (tipoSalto) //Elijo el tipo de salto (hacia dónde va el mvto. vertical)
	{	
		case (NORMAL):
			if (saltosRestantes > 0) //Si hay saltos restantes
			{
				velocidad.y = vSalto; //Velocidad en Y para hacer un salto normal (hacia arriba)
				saltosRestantes--; //resto 1 al número de saltos
			}
			break;

		case (PARED_DCHA): //Ángulo de 45 grados SOLO SI la vel. de mvto. y la de salto son iguales, sino se necesitan más cálculos.
			velocidad.x = -vMov * COS_45;
			velocidad.y = vSalto * SEN_45;
			contactoParedDcha = false;
			break;

		case (PARED_IZQ): 
			velocidad.x = vMov * COS_45;
			velocidad.y = vSalto * SEN_45;
			contactoParedIzq = false;
			break;

		case (CARGADO):
			velocidad.y = multiplicadorCargado*vSalto;
			saltosRestantes--;
			break;	
	}
}
void Personaje::Dash(unsigned char direccion) { //Añadir SHIFT + A, S, D
	/*case (DASH_ABAJO):
		velocidad.y = -vSalto;
		break;*/
}