#pragma once
#include "Rectangulo.h"
#include "RectanguloMovil.h"
#include "ListaRectangulos.h"
#include "Caja.h"
#include "Personaje.h"
#include "Interaccion.h"
#include "Sierra.h"
#include "pinchos.h"
#include "PowerUp.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void SetVelMundo(float velocidad);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void SetOjo(float x, float y, float z);
	float GetOjo();
	bool GetMuerte();

private:
	Caja caja;
	Personaje personaje;
	Rectangulo rectangulo1;
	ListaRectangulos plataformas;
	ListaRectangulos pinchos;
	ListaRectangulos powerUps;

	Sierra sierra,sierra2;

	float x_ojo;
	float y_ojo;
	float z_ojo;

	bool muerte;
};