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
		switch (Interaccion::Choque(pared.suelo, personaje.cuerpo))
		{
		case 1:
			personaje.setSaltosRes(4);
			personaje.SetAcc(0.0, 0.0);
			personaje.SetVel(0.0, 0.0);
			return true;
		case 2:
			return true;
		case 3:
			return true;
		case 4:
			return true;
		}
	}	
	else if (Interaccion::Choque(pared.techo, personaje.cuerpo) || Interaccion::Choque(pared.paredD, personaje.cuerpo) || Interaccion::Choque(pared.paredI, personaje.cuerpo))
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
		switch (Interaccion::Choque(rectangulo, personaje.cuerpo))
		{
		case 1:
			personaje.setSaltosRes(4);
			personaje.SetAcc(0.0, 0.0);
			personaje.SetVel(0.0, 0.0);
			return true;
		case 2:
			personaje.SetVel(0.0, 0.0);
			return true;
		case 3:
			personaje.SetVel(0.0, 0.0);
			return true;
		case 4:
			personaje.SetVel(0.0, 0.0);
			return true;
		}
	}
	else
	{
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

void Interaccion::Choque(ListaRectangulos& listaRectangulos, Personaje& personaje)
{
	for (int i = 0; i < listaRectangulos.GetNum(); i++)
	{
		Interaccion::Choque(*listaRectangulos.lista[i], personaje);
	}
}