#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

class Personaje : public ObjetoMovil
{
public:
	Personaje();
	virtual ~Personaje();

	void Dibuja();

	void mueve(float t);	//poner la m en mayúscula.
	void mueve(unsigned char dir);

	void Salta(bool solicitado, unsigned int tipo);

	void setSaltosRes(int saltosIn);
	int getSaltosRes(void);

private:
	Rectangulo cuerpo;
	int saltosRestantes;
	float vMov; //Velocidad de movimiento lateral
	float vSalto; //Veocidad inicial en el eje y que genera el salto
};

