#pragma once

#include "Entidad.h"
#include "Rectangulo.h"
#include "ListaRectangulos.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;
using ETSIDI::Sprite;

class Personaje : public Entidad
{
public:
	friend class Interaccion;
	Personaje();
	virtual ~Personaje();

	void Inicializa();
	void Dibuja();

	void Mueve(float t, ListaRectangulos& plataformas);
	void Tecla(unsigned char key);

	void Salta( unsigned int tipoSalto);

	void SetSaltosRes(int saltosIn);
	int GetSaltosRes(void);

	void SetPowerUpDisponible(int powerUpDisponibleIn);

private:
	Rectangulo cuerpo;
	int saltosRestantes;
	int powerUpDisponible;
	float vMov; //Velocidad de movimiento lateral
	float vSalto; //Veocidad inicial en el eje y que genera el salto
	bool contactoParedDcha;
	bool contactoParedIzq;
	float multiplicadorCargado;

	int plataformaEnContacto; //Plataforma sobre la que está posado el personaje

	bool dchaPresionado;
	bool izqPresionado;

	//SpriteSequence sprite;
	SpriteSequence sprite;
	SpriteSequence sprite_camina;
	Sprite sprite_salto;
	Sprite sprite_caida;
};