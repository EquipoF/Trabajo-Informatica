#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Rectangulo: public ObjetoMovil
{
public:
	friend class Interaccion;
	Rectangulo();//Temporalmente cuadrado rojo estandar
	Rectangulo(float anchoIn, float altoIn, Vector2D centroIn);
	Rectangulo( Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn);
	virtual ~Rectangulo();
	void Dibuja();
	void SetCentro(Vector2D centroIn);
	void SetCentro(float x, float y);
	Vector2D GetCentro();
	void SetAnchoAlto(Vector2D anchoAltoIn);
	Vector2D GetAnchoAlto();
	bool GetMovil();

protected:
	void CentroVertice();
	void VerticeCentro();
	float alto, ancho;
	Vector2D centro;//Centro del rectángulo
	Vector2D arribaDcha, arribaIzq, abajoIzq, abajoDcha; //Esquinas del rectángulo
	bool movil;
};

