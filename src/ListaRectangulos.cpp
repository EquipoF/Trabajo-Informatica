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
		//lista[i]->Dibuja();

		//intento de poner imagen a las plataformas
		Vector2D centro = lista[i]->GetCentro();
		Vector2D anchoAlto = lista[i]->GetAnchoAlto();

		glPushMatrix();
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plat_4.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex2f(centro.x - (anchoAlto.x / 2), centro.y - (anchoAlto.y / 2));
		glTexCoord2d(1, 1);		glVertex2f(centro.x + (anchoAlto.x / 2), centro.y - (anchoAlto.y / 2));
		glTexCoord2d(1, 0);		glVertex2f(centro.x + (anchoAlto.x / 2), centro.y + (anchoAlto.y / 2));
		glTexCoord2d(0, 0);		glVertex2f(centro.x - (anchoAlto.x / 2), centro.y + (anchoAlto.y / 2));
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
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