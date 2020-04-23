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
	static int choque(Rectangulo& r1, Rectangulo& r2);
	static bool choque(Rectangulo& rectangulo, Personaje& personaje);

};

