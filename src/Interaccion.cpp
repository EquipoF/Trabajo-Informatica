#include "Interaccion.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::Choque(Caja &pared, Personaje &personaje)
{
	if ( Interaccion::Choque(pared.suelo, personaje.cuerpo) )
		
	{
		switch (Interaccion::choque(pared.suelo, personaje.cuerpo))
		{
		case 1:
			personaje.setSaltosRes(4);
			personaje.setAcc(0.0, 0.0);
			personaje.setVel(0.0, 0.0);
			return true;
		case 2:
			return true;
		case 3:
			return true;
		case 4:
			return true;
		}	
	}	
	else if (Interaccion::choque(pared.techo, personaje.cuerpo) || Interaccion::choque(pared.paredD, personaje.cuerpo) || Interaccion::choque(pared.paredI, personaje.cuerpo))
	{
		return true;
	}
	else
	{
		personaje.SetAcc(0.0, -4.0);
		return false;
	}

}

bool Interaccion::Choque(Rectangulo& rectangulo, Personaje& personaje)
{
	Vector2D posAnterior = personaje.GetPosAnt();
	if (Interaccion::Choque(rectangulo, personaje.cuerpo))
	{
		personaje.SetPos(posAnterior);
		personaje.SetVel(0.0, 0.0);
		return true;
	}
	else
	{
		return false;
	}
}

int Interaccion::choque(Rectangulo& r1, Rectangulo& r2)
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

	if (choque == false)
		return 0;
	else if (choque == true && r2.centro.y > r1.centro.y && (distanciaMax.y - distancia.y) < (distanciaMax.x - distancia.x))
		return 1;
	else if (choque == true && r2.centro.x > r1.centro.x && (distanciaMax.y - distancia.y) > (distanciaMax.x - distancia.x))
		return 2;
	else if (choque == true && r2.centro.y < r1.centro.y && (distanciaMax.y - distancia.y) < (distanciaMax.x - distancia.x))
		return 3;
	else if (choque == true && r2.centro.x < r1.centro.x && (distanciaMax.y - distancia.y) >(distanciaMax.x - distancia.x))
		return 4;
	else
		return 4;
}

int Interaccion::Choque(ListaRectangulos& listaRectangulos, Personaje& personaje)
{
	int i = 0;

	while (i < listaRectangulos.GetNum())
	{
		Interaccion::Choque(*listaRectangulos.lista[i], personaje);
		i++;
	}
	if (i <= 0)
	{
		return i;
	}
	else
	{
		return -1;
	}
}