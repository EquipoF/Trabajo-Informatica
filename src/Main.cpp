#include "Mundo.h"
#include "glut.h"

#define STOP_EJE_X 'S'
#define ESPACIO_SOLTADO 0

Mundo mundo;

float aspect = 1.0f;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y); //cuando se deja de pulsar una tecla

void onSize(int sx, int sy)//funcion para poder cambiar tama�o de la ventana sin que se deformen las cosas
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
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
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
	//poner aqui el c�digo de teclado
	mundo.Tecla(key);

	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	if ((key == 'a') || (key == 'd'))
	{
		mundo.Tecla(STOP_EJE_X); // cuando a mundo le llega 'S' pone velocidad personaje a 0
	}
	else if (key == ' ') 
	{
		mundo.Tecla(ESPACIO_SOLTADO); 
	}

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el c�digo de animacion
	mundo.Mueve();

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
