#pragma once

#include "Rectangulo.h"
#include "ListaRectangulos.h"
#include "Sierra.h"
#include "ListaSierras.h"

#include "Personaje.h"
#include "Caja.h"
#include "pinchos.h"
#include "PowerUp.h"

#include "Interaccion.h"
#include "FinalNivel.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);

	void Inicializa();
	void Mueve();
	void Dibuja();

	void CargarNivel();
	void RandPlatforms();

	void SetOjo();
	void SetVelMundo(float velocidad);
	float GetOjo();
	bool GetMuerte();
	bool GetFinal();

private:
	Caja caja;
	Personaje personaje;
	ListaRectangulos plataformas;
	ListaRectangulos pinchos; //Gracias al polimorfismo y la herencia
	ListaRectangulos powerUps; //Gracias al polimorfismo y la herencia
	ListaSierras sierras; 

	FinalNivel finalnivel;

	float x_ojo;
	float y_ojo;
	float z_ojo;

	bool muerte;
	bool final;
	int nivel;

	float tiempo;
};