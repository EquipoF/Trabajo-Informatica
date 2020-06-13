#include "Pinchos.h"

//Estados de los pinchos
enum { GUARDADOS = 1, SALIENDO = 2, FUERA = 3 };

Pinchos::Pinchos(Rectangulo rectanguloIn, bool movilIn, unsigned int lado, float tiniIn) //1-> arriba, 2->abajo, 3-> dcha, 4-> izq. por defecto arriba
{
	//Generar el rectángulo que hace de plataforma
	switch (lado)
	{
	case 0:
	case 1:
		centro = rectanguloIn.GetCentro() + Vector2D(0.0, rectanguloIn.GetAnchoAlto().y);
		break;
	case 2:
		centro = rectanguloIn.GetCentro() - Vector2D(0.0, rectanguloIn.GetAnchoAlto().y);
		break;
	case 3:
		centro = rectanguloIn.GetCentro() + Vector2D(rectanguloIn.GetAnchoAlto().x, 0.0);
		break;
	case 4:
		centro = rectanguloIn.GetCentro() - Vector2D(rectanguloIn.GetAnchoAlto().x, 0.0);
		break;
	}
	ancho = rectanguloIn.GetAnchoAlto().x;
	alto = rectanguloIn.GetAnchoAlto().y;
	CentroVertice();
	movil = movilIn;
	tini = tiniIn;
	estado = FUERA;
}
Pinchos::Pinchos()
{
	Rectangulo::Rectangulo();
	movil = false;
	estado = FUERA;
} 
Pinchos::~Pinchos()
{

}

void Pinchos::Mueve(float t) {
	Pinchos::Salir(t);
}
void Pinchos::Salir(float t)
{
	//Pinchos guardados en el suelo, cada x tiempo, hacen una señal y un poco despúes salen del suelo y se mantienen durante otro rato.
	static float contador = tini; //Variable para almacenar el tiempo del ciclo de los pinchos

	if (movil) //Si son pinchos que salen y entran del suelo, es decir, no son estáticos
	{
		if (contador < 1.0f) // de 0 a 1s guardados
		{
			estado = GUARDADOS;
			atravesar = true;
		}
		else if (contador < 1.5f) //de 1 a 2s saliendo
		{
			estado = SALIENDO;
			atravesar = true;
		}
		else if (contador < 2.5f) //de 1.5 a 2.5s fuera
		{
			estado = FUERA;
			atravesar = false;
		}
		else //A los 2.5s resetea
		{
			contador = 0;
		}
		contador += t; //Se añade el tiempo que pasa en el mundo al contador
	}
}

void Pinchos::Dibuja()
{
	switch (estado) 
	{
	case GUARDADOS:
		//No dibuja nada
		break;
	case SALIENDO:
		//Dibuja las puntas de los pinchos en el suelo
		break;
	case FUERA:
		Rectangulo::Dibuja();//Dibuja los pinchos fuera
		break;
	}
}

int Pinchos::GetEstado() 
{
	return estado;
}