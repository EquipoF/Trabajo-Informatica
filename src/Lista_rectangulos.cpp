
#include "Lista_rectangulos.h"

Lista_rectangulos::Lista_rectangulos()
{

}

Lista_rectangulos::~Lista_rectangulos()
{

}

bool Lista_rectangulos::agregar(Rectangulo* rec)
{
	lista.push_back(rec);
	return true;
}

void Lista_rectangulos::dibuja()
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}

void Lista_rectangulos::eliminarRectangulo(int ind)
{
	if ((ind < 0) || (ind >= lista.size()))
		return;

	delete lista[ind];
	lista.erase(lista.begin() + ind);
}