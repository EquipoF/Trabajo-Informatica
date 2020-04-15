#include "Rectangulo.h"
#include "Caja.h"
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
	Rectangulo rectangulo1, suelo;
	float x_ojo;
	float y_ojo;
	float z_ojo;
};

//esto es una prueba