#include "Interaccion.h"

enum { ARRIBA = 1, ABAJO = 3, PARED_DCHA = 4, PARED_IZQ = 2 };

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

int Interaccion::Choque(Caja & caja, Personaje& personaje)
{
	return Interaccion::Choque(caja.ladosCaja, personaje);
}

bool Interaccion::Choque(Rectangulo& rectangulo, Personaje& personaje)
{
	//Vector2D posAnterior = personaje.GetPosAnt(); // Ya se hace en los casos
	Vector2D posActual = personaje.GetPos();
	Vector2D velActual = personaje.GetVel();
	Vector2D accActual = personaje.GetAcc();

	Rectangulo cuerpoFuturo(personaje.cuerpo.ancho, personaje.cuerpo.alto, personaje.GetPos());

	if (Interaccion::Choque(rectangulo, cuerpoFuturo))
	{
		switch (Interaccion::Choque(rectangulo, cuerpoFuturo))
		{
		case ARRIBA:
			personaje.setSaltosRes(2);
			personaje.SetPos(posActual.x, rectangulo.centro.y + ( (personaje.cuerpo.alto / 2) + (rectangulo.alto / 2) + 0.01) ); //Ponemos el pesonaje justo encima de la plataforma
			personaje.SetAcc(accActual.x, 0.0);
			personaje.SetVel(0.0, 0.0);
			return true;
		case PARED_DCHA:
			personaje.SetPos( rectangulo.centro.x - ((personaje.cuerpo.ancho / 2) + (rectangulo.ancho / 2) + 0.01), posActual.y); //Ponemos el pesonaje justo a la derecha de la plataforma
			personaje.SetVel(0.0, velActual.y);
			personaje.SetAcc(0.0, accActual.y);
			personaje.contactoParedDcha = true;
			return true;
		case PARED_IZQ:
			personaje.SetPos(rectangulo.centro.x + ((personaje.cuerpo.ancho / 2) + (rectangulo.ancho / 2) + 0.01) , posActual.y); //Ponemos el pesonaje justo a la iquierda de la plataforma
			personaje.SetVel(0.0, velActual.y);
			personaje.SetAcc(0.0, accActual.y);
			personaje.contactoParedIzq = true;
			return true;
		case ABAJO:
			personaje.SetPos(posActual.x, rectangulo.centro.y - ((personaje.cuerpo.alto / 2) + (rectangulo.alto / 2) + 0.01)); //Ponemos el pesonaje justo encima de la plataforma
			personaje.SetVel(velActual.x, 0.0);
			return true;
		}
	}
	else
	{
		personaje.contactoParedDcha = false; //Para que no se quede la opción de salto de pared activa par siempre si tocas una pared
		personaje.contactoParedIzq = false;
		return false;
	}
}

int Interaccion::Choque(Rectangulo& r1, Rectangulo& r2)
{
	bool choque;
	Vector2D distancia;
	Vector2D distanciaMax;

	distanciaMax.x = (r1.ancho / 2) + (r2.ancho / 2);
	distanciaMax.y = (r1.alto / 2) + (r2.alto / 2);

	distancia.x = abs(r1.centro.x - r2.centro.x);
	distancia.y = abs(r1.centro.y - r2.centro.y);

	if (distancia.x < distanciaMax.x && distancia.y < distanciaMax.y)
		choque = true;
	else
		choque = false;

	if (choque == false)	//si no hay choque
		return 0;
	else if (choque == true && r2.centro.y > r1.centro.y && (distanciaMax.y - distancia.y) < (distanciaMax.x - distancia.x)) //bruh
		return ARRIBA;
	else if (choque == true && r2.centro.x > r1.centro.x && (distanciaMax.y - distancia.y) > (distanciaMax.x - distancia.x))
		return PARED_IZQ;
	else if (choque == true && r2.centro.y < r1.centro.y && (distanciaMax.y - distancia.y) < (distanciaMax.x - distancia.x))
		return ABAJO;
	else if (choque == true && r2.centro.x < r1.centro.x && (distanciaMax.y - distancia.y) >(distanciaMax.x - distancia.x))
		return PARED_DCHA;
	else
		return PARED_DCHA;
}

int Interaccion::Choque(ListaRectangulos& listaRectangulos, Personaje& personaje)
{
	int rectanguloChocado = -1; //Si no choca con ninguna plataforma se devuelve -1

	for (int i = 0; i < listaRectangulos.GetNum(); i++)
	{
		if (Interaccion::Choque(*listaRectangulos.lista[i], personaje))
		{
			rectanguloChocado = i;
			return rectanguloChocado;
		}
	}
	return rectanguloChocado;
}

bool Interaccion::Choque(Sierra& sierra, Personaje& personaje)
{
	bool choque = false;
	float dif = (personaje.posicion - sierra.posicion).modulo() - ((personaje.cuerpo.ancho + 0.3f) + 0.1f);
	if (dif <= 0.0f)
	{
		choque = true;
	}
	return choque;
}

bool Interaccion::SalidaLateral(ListaRectangulos& listaRectangulos, Personaje& personaje)
{
	Vector2D accActual = personaje.GetAcc();

	//Saco el rectángulo que necesito de la lista
	Rectangulo rectangulo = *listaRectangulos.lista[personaje.plataformaEnContacto];

	//Comprobar que los centros se encuantras a más distancia que la suma de los semi-anchos
	//Salida por la derecha y la izquierda gracias al absoluto
	if (abs(personaje.cuerpo.centro.x - rectangulo.centro.x) >= (personaje.cuerpo.ancho/2 + rectangulo.ancho/2))
	{
		personaje.SetAcc(accActual.x, -10.0f);
		personaje.plataformaEnContacto = -1;
		return 1;
	}
	return 0;
}