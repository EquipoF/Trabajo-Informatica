#pragma once
#include "Rectangulo.h"
#include <vector>

class ListaRectangulos
{
public:
	friend Interaccion;
	ListaRectangulos();
	virtual ~ListaRectangulos();

	bool Agregar(Rectangulo* rec);
	void Dibuja();
	void EliminarRectangulo(int ind);

	int GetNum();

private:
	std::vector<Rectangulo*> lista;
};