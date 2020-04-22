#pragma once
#include "Rectangulo.h"
#include <cstdlib>
#include "Caja.h"
#include "Personaje.h"

class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();

	static bool choque(Caja& pared, Personaje& personaje);

};

