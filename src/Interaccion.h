#pragma once
#include "Rectangulo.h"
#include <cstdlib>
#include "Caja.h"
#include "Personaje.h"
#include "ListaRectangulos.h"

class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();

	static bool Choque(Caja& caja, Personaje & personaje);
	static int Choque(Rectangulo& r1, Rectangulo& r2);
	static bool Choque(Rectangulo& rectangulo, Personaje & personaje);
	static bool Choque(ListaRectangulos& listaRectangulo, Personaje & personaje);

};

