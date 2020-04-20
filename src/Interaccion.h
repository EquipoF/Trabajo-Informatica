#pragma once
#include "Caja.h"
#include "Personaje.h"

class Interaccion
{
public:
	Interaccion();
	~Interaccion();

	static bool colision(Personaje &h, Caja c);
	static bool colision_suelo(Personaje& h, Caja c);
};
