#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

class Personaje : public ObjetoMovil
{
public:
	Personaje();
	virtual ~Personaje();

	void Dibuja();

	void Mueve(float t);	//poner la m en mayúscula.

	void Tecla(unsigned char key);

	void Salta( unsigned int tipoSalto);

	void setvSalto(float vIn);
	void setvMov(float vIn);
	void setSaltosRes(int saltosIn);
	int getSaltosRes(void);

private:
	Rectangulo cuerpo;
	int saltosRestantes;
	float vMov; //Velocidad de movimiento lateral
	float vSalto; //Veocidad inicial en el eje y que genera el salto
	bool contactoParedDcha;
	bool contactoParedIzq;
};

