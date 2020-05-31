#pragma once
#include "Rectangulo.h"
#include <cstdlib>
#include "Caja.h"
#include "Personaje.h"
#include "ListaRectangulos.h"
#include "Sierra.h"

class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();

	static int Choque(Caja& caja, Personaje & personaje);
	static int Choque(Rectangulo& r1, Rectangulo& r2);
	static bool Choque(Rectangulo& rectangulo, Personaje & personaje);
	static int Choque(ListaRectangulos& listaRectangulo, Personaje & personaje);
	static bool Choque(Sierra& sierra, Personaje& personaje);
	static bool SalidaLateral(ListaRectangulos &listaRectangulos, Personaje &personaje);
};

