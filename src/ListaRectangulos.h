#pragma once
#include "Rectangulo.h"
#include <vector>

class ListaRectangulos
{
public:
	ListaRectangulos();
	virtual ~ListaRectangulos();

	bool agregar(Rectangulo* rec);
	void dibuja();
	void eliminarRectangulo(int ind);

private:
	std::vector<Rectangulo*> lista;
};