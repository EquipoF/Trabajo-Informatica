#pragma once
#include "Vector2D.h"
class Rectangulo
{
public:
	Rectangulo();//Temporalmente cuadrado rojo estandar
	Rectangulo(float anchoIn, float altoIn, Vector2D centroIn);//Queda por rellenar
	Rectangulo( Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn);
	virtual ~Rectangulo();

	void Dibuja();
	void setCentro(Vector2D centroIn);	void setCentro(float xIn, float yIn); //Falta implementación en el .cpp

private:
	float alto, ancho;
	Vector2D centro;
	Vector2D arribaDcha, arribaIzq, abajoIzq, abajoDcha;
};

