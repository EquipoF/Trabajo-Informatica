#pragma once
#include "Rectangulo.h"
#include "RectanguloMovil.h"
#include "ListaRectangulos.h"
#include "ListaSierras.h"
#include "Caja.h"
#include "Personaje.h"
#include "Interaccion.h"
#include "Sierra.h"
#include "pinchos.h"
#include "PowerUp.h"
#include "FinalNivel.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void SetVelMundo(float velocidad);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void SetOjo();
	float GetOjo();
	bool GetMuerte();
	bool GetFinal();
	void CargarNivel();
	void RandPlatforms();

private:
	Caja caja;
	Personaje personaje;
	Rectangulo rectangulo1;
	ListaRectangulos plataformas;
	ListaRectangulos pinchos;
	ListaRectangulos powerUps;
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