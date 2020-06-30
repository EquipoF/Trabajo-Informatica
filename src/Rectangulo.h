#pragma once
#include "Vector2D.h"
#include "Entidad.h"
class Rectangulo: public Entidad
{
public:
	friend class Interaccion;

	Rectangulo();//Crea un cuadrado rojo estandar
	Rectangulo(float anchoIn, float altoIn, Vector2D centroIn, bool movilIn = false, float limDchaIn = 0, float limIzqIn = 0, float limArribaIn = 0, float limAbajoIn = 0, float velXIn = 0, float velYIn = 0);
	Rectangulo(Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn);
	virtual ~Rectangulo();

	virtual void Dibuja();
	virtual void Mueve(float t);

	void SetCentro(Vector2D centroIn);
	void SetCentro(float x, float y);
	Vector2D GetCentro();
	void SetAnchoAlto(Vector2D anchoAltoIn);
	Vector2D GetAnchoAlto();

protected:
	void CentroVertice();
	void VerticeCentro();
	float alto, ancho;
	Vector2D centro;//Centro del rectángulo
	Vector2D arribaDcha, arribaIzq, abajoIzq, abajoDcha; //Esquinas del rectángulo (para dibujar con la glut)
};