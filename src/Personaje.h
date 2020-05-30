#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"
//#include "Interaccion.h"
#include "ListaRectangulos.h"
#include "Caja.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
using ETSIDI::Sprite;

class Personaje : public ObjetoMovil
{
public:
	friend class Interaccion;
	Personaje();
	virtual ~Personaje();

	void Dibuja();
	void Inicializa();

	void Mueve(float t, ListaRectangulos& plataformas, Caja& caja);	//poner la m en mayúscula.

	void Tecla(unsigned char key);

	void Dash(unsigned char direccion);
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
	float multiplicadorCargado;

	bool dchaPresionado = false;
	bool izqPresionado = false;

	//SpriteSequence sprite;
	SpriteSequence sprite;
	Sprite sprite_salto;
	Sprite sprite_caida;
};

