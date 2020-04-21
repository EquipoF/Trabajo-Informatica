#include "Rectangulo.h"
#include "Caja.h"
#include "Personaje.h"

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

private:
	Caja caja;
	Personaje personaje;
	Rectangulo rectangulo1, suelo;
	float x_ojo;
	float y_ojo;
	float z_ojo;
};

//esto es una prueba