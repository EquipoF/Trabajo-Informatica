#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"
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

	void Inicializa();
	void Dibuja();

	void Mueve(float t, ListaRectangulos& plataformas, Caja& caja);
	void Tecla(unsigned char key);

	void Salta( unsigned int tipoSalto);
	//void Dash(unsigned char direccion);

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

	int plataformaEnContacto; //Plataforma sobre la que está posado el personaje

	bool dchaPresionado = false;
	bool izqPresionado = false;

	//SpriteSequence sprite;
	SpriteSequence sprite;
	Sprite sprite_salto;
	Sprite sprite_caida;
};