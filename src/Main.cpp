#include "Mundo.h"
#include "glut.h"

#define DIFF_TIEMPO_MAIN 15

//Misma enum que en Personaje.cpp 
enum { DCHA = 'd', IZQ = 'a', ABAJO = 's', ESPACIO = ' ', ESPACIO_SOLTADO = 0, DCHA_SOLTADO = 1, IZQ_SOLTADO = 2, ABAJO_SOLTADO = 3 };

Mundo mundo;

float aspect = 1.0f;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y); //cuando se deja de pulsar una tecla

void onSize(int sx, int sy)//funcion para poder cambiar tamaño de la ventana sin que se deformen las cosas
{
	glViewport(0, 0, sx, sy);
	aspect = (float)sx / (float)sy;
}

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(420, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, aspect, 0.1, 100);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(DIFF_TIEMPO_MAIN,OnTimer,0);//le decimos que dentro de 5ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutReshapeFunc(onSize);

	mundo.Inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40.0f, aspect, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	mundo.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	mundo.Tecla(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{//Se puede cambiar por un switch
	switch (key)
	{
	case DCHA:
		mundo.Tecla(DCHA_SOLTADO);
		break;
	case IZQ:
		mundo.Tecla(IZQ_SOLTADO);
		break;
	case ABAJO:
		mundo.Tecla(ABAJO_SOLTADO);
		break;
	case ESPACIO:
		mundo.Tecla(ESPACIO_SOLTADO);
		break;
	}
	glutPostRedisplay();
}

void keyManagement(unsigned char key)
{

}

void OnTimer(int value)
{
//poner aqui el código de animacion
	mundo.Mueve();

	//no borrar estas lineas
	glutTimerFunc(DIFF_TIEMPO_MAIN,OnTimer,0);
	glutPostRedisplay();
}