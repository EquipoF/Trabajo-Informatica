#include "ListaRectangulos.h"

ListaRectangulos::ListaRectangulos()
{

}

ListaRectangulos::~ListaRectangulos()
{

}

bool ListaRectangulos::Agregar(Rectangulo* rec)
{
	lista.push_back(rec);
	return true;
}

void ListaRectangulos::Dibuja()
{
	for (int i = 0; i < lista.size(); i++)
	{
		lista[i]->Dibuja();
	}		
}

void ListaRectangulos::EliminarRectangulo(int ind)
{
	if ((ind < 0) || (ind >= lista.size()))
		return;

	delete lista[ind];
	lista.erase(lista.begin() + ind);
}

int ListaRectangulos::GetNum(void) {
	return lista.size();
}

void ListaRectangulos::DestruirContenido()
{
	int numero = lista.size();

	for (int i = 0; i < numero; i++)
	{
		EliminarRectangulo(i);
	}

	numero = 0;
}