#pragma once
#include "Rectangulo.h"
#include <vector>

class Lista_rectangulos
{
public:
	Lista_rectangulos();
	virtual ~Lista_rectangulos();

	bool agregar(Rectangulo* rec);
	void dibuja();
	void eliminarRectangulo(int ind);

private:
	std::vector<Rectangulo*> lista;
};