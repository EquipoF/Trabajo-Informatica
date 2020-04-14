#pragma once
#include "Vector2D.h"
class Rectangulo
{
public:
	Rectangulo();//Temporalmente cuadrado rojo estandar
	Rectangulo(float anchoIn, float altoIn, Vector2D centroIn);//Queda por rellenar
	Rectangulo( Vector2D arribaIIn, Vector2D arribaDIn, Vector2D abajoDIn, Vector2D abajoIIn);
	virtual ~Rectangulo();
	void Dibuja();
private:
	float alto, ancho;
	Vector2D centro;
	Vector2D arribaD, arribaI, abajoI, abajoD;
};

