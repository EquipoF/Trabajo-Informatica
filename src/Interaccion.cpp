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
		personaje.SetAcc(0.0, 0.0);
		personaje.SetVel(0.0, 0.0);
		return true;
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

bool Interaccion::Choque(Rectangulo& r1, Rectangulo& r2)
{
	Vector2D distancia;

	distancia.x = abs(r1.centro.x - r2.centro.x);
	distancia.y = abs(r1.centro.y - r2.centro.y);

	if (distancia.x < ((r1.ancho / 2) + (r2.ancho / 2)) && distancia.y < ((r1.alto / 2) + (r2.alto / 2)))
	{
		return true;
	}
	else
	{
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

int Interaccion::Choque(ListaRectangulos& listaRectangulos, Personaje& personaje)
{
	int i = 0;

	while ( i < listaRectangulos.GetNum()) 	
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
