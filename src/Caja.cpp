#include "Caja.h"

Caja::Caja()// La caja tiene, con las dimensiones de ventana 800*600, un ancho de 20 y un alto de 14
{
	//Usar atributos ancho y alto para generar la caja plsssss	

	//Creamos los lados de la caja
	suelo = Rectangulo(22.0, 2.0, Vector2D(0, -7));
	techo = Rectangulo(22.0, 1.0, Vector2D(0, 43));
	paredDcha = Rectangulo(2.0, 52.0, Vector2D(10, 18));
	paredIzq = Rectangulo(2.0, 52.0, Vector2D(-10, 18));

	//los incluimos en la lsta de lados para manejarlos cómodamente
	ladosCaja.Agregar(&paredDcha);	ladosCaja.Agregar(&paredIzq);	ladosCaja.Agregar(&suelo);	ladosCaja.Agregar(&techo);
}

Caja::~Caja()
{
	
}

void Caja::Dibuja()
{
	ladosCaja.Dibuja();
}
