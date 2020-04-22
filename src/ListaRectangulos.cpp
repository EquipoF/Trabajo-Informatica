#include "ListaRectangulos.h"

ListaRectangulos::ListaRectangulos()
{

}

ListaRectangulos::~ListaRectangulos()
{

}

bool ListaRectangulos::agregar(Rectangulo* rec)
{
	lista.push_back(rec);
	return true;
}

void ListaRectangulos::dibuja()
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->Dibuja();
}

void ListaRectangulos::eliminarRectangulo(int ind)
{
	if ((ind < 0) || (ind >= lista.size()))
		return;

	delete lista[ind];
	lista.erase(lista.begin() + ind);
}