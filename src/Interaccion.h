#pragma once
#include "Rectangulo.h"
#include <cstdlib>

class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();

	static bool choque(Rectangulo& pared, Rectangulo& personaje);

};

