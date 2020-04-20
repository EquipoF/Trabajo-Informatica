#pragma once
#include "Rectangulo.h"
#include "Caja.h"
#include "Personaje.h"
//#include "Lista_rectangulos"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void SetOjo(float x, float y, float z);
	float GetOjo();

private:
	Caja caja;
	Personaje personaje;
	Rectangulo rectangulo1, suelo;
	//Lista_rectangulos l_rectangulos;

	float x_ojo;
	float y_ojo;
	float z_ojo;
};