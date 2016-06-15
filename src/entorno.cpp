/**
ELEMENTOS DE PROGDRAMACIÓN
Curso 2009/2010

Nombre: ENTORNO.cpp
Descripción: Implementaciónn del TAD Entorno para el proyecto MAGNETÓN. 
	     Encargado del manejo de la interfaz del juego	
Autor:       Profesores de la asignatura
Fecha de creación:	18/11/2010

*/

#include "entorno.h"

#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

const int MAX_CADENA= 20; //Número máximo de caracteres para una cadena
BITMAP *fichas[MAX_FICHAS];  // vector que contiene enlace a las imágenes de las fichas



// prototipo de una función privada que se usa a lo largo de la implementación del TAD, 
//pero que no forma  parte del TAD.
void TEntornoPonerColorCasilla(int x, int y, int colorpair, int valor) ;


// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------

const int ANCHO_VENTANA=800;
const int ALTO_VENTANA=600;

/**
	Definicón de constantes para posicionar los números en el tablero
*/
const int DISTANCIA_COLS=55;  // Distancia entre columnas
const int DISTANCIA_FILAS=55;  // Distancia entre filas
const int ORIGEN_X=20;  // Origen de las x
const int ORIGEN_Y=20;  // Origen de las y 

// -------------------------------------------------------------
// Operaciones
// -------------------------------------------------------------
//define el color en función de los valores makecol - allegro library
int makecolor2(int color){
  int col;
  switch (color){
    case COLOR_BLANCO: col=makecol( 255, 255, 255); break;
    case COLOR_ROJO: col=makecol( 255, 0, 0); break;
    case COLOR_NARANJA:col=makecol( 255, 128, 0); break;
    case COLOR_AMARILLO: col=makecol( 255, 255, 0); break;
    case COLOR_VERDE:col=makecol( 0, 255, 0); break;
    default:  col=makecol( 255, 255, 255); break; //color blanco
  }
    return col;
}


// Dibuja en la pantalla el borde de un tablero con el ancho indicado
void TEntornoPintarRejilla(int f, int c) {
        // Comenzamos en la 0,0	
	
	int x,y;
	int i,j;
	acquire_screen();
	// horizontales
	for (i=0;i<=c;i++)
	  line( screen, ORIGEN_X+0*DISTANCIA_COLS, ORIGEN_Y+i*DISTANCIA_FILAS, ORIGEN_X+c*DISTANCIA_COLS, ORIGEN_Y+i*DISTANCIA_FILAS, makecol( 255, 255, 255)); 
	
	//verticales
	for (i=0;i<=f;i++)
	  line( screen, ORIGEN_X+i*DISTANCIA_COLS, ORIGEN_Y+0*DISTANCIA_FILAS, ORIGEN_X+i*DISTANCIA_COLS, ORIGEN_Y+f*DISTANCIA_FILAS, makecol( 255, 255, 255)); 
	
	textout_ex( screen, font, " ***    DIAMANTES   ***",  600,50 , makecol( 255, 255, 255), makecol(0, 0, 0));
	textout_ex( screen, font, "PROYECTO DE PROGRAMACIÓN",  600,70 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	textout_ex( screen, font, "TECLAS:",  600,120 , makecol( 255, 255, 255), makecol(0, 0, 0));
	textout_ex( screen, font, "Arriba: Fecha arriba",  600,140 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	textout_ex( screen, font, "Abajo: Flecha abajo",  600,160 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	textout_ex( screen, font, "Derecha: Flecha derecha",  600,180 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	textout_ex( screen, font, "Izquier: Flecha izquierda",  600,200 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	textout_ex( screen, font, "Seleccionar: Enter",  600,220 , makecol( 255, 255, 255), makecol(0, 0, 0));
	textout_ex( screen, font, "Salir: Escape",  600,240 , makecol( 255, 255, 255), makecol(0, 0, 0));  
	TEntornoMostrarPuntos(0) ;
	
	release_screen();

	
}

bool TEntornoCargarConfiguracion(int &tamanio, int &fichas, int &nflinea, bool &aleatorio, int datos[MAX_TAMANIO][MAX_TAMANIO]){
	ifstream entrada;
	char cad_tamanio[MAX_CADENA+1], cad[MAX_CADENA+1];
	bool ok=true;
	
	
	entrada.open("diamante.cnf");
	if (entrada == 0 ){
		cout<<"Fichero de configuración no encontrado."<<endl;
		ok=false;
	}
	else {
		entrada.getline(cad_tamanio, 10);
		tamanio = atoi(cad_tamanio);

		entrada.getline(cad_tamanio, 10);
		fichas = atoi(cad_tamanio);

		entrada.getline(cad_tamanio, 10);
		nflinea = atoi(cad_tamanio);		
		
		entrada.getline(cad_tamanio, 10);
		aleatorio = (bool) atoi(cad_tamanio);	
		if (!aleatorio)
		  for (int i=0;i<tamanio;i++) {
		      entrada.getline(cad_tamanio, MAX_CADENA);
		      for (int j=0;j<tamanio;j++)
			  datos[i][j]=cad_tamanio[j]-48;
		  }    
		  

		entrada.close();
		
	}
	return ok;
}



void TEntornoIniciarPantalla (int f, int c, int nfichas) {
  char nomfig[20];
  // Iniciar el entorno
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
   
  
  // Pintar regilla
  TEntornoPintarRejilla(f,c);
  
  //inicio del vector de fichas a MULL
  for (int i=0;i<nfichas;i++) {
    sprintf(nomfig,"f%d.bmp",i);  // asigna el nomnbre de la figura a  cargar
    fichas[i]=  load_bitmap( nomfig, NULL);    
  }
  //fichas[2]=  load_bitmap( "f2.bmp", NULL);    
}

void TEntornoIniciarPantalla (int tamanio, int nfichas) {
	TEntornoIniciarPantalla (tamanio, tamanio, nfichas);
}

/********************************************/

void TEntornoActivarCasilla(int fila, int columna, int color) {
    char cad[20];
    
    sprintf(cad,"%d-%d",columna,fila);
    // Pinta de trazo distinto la ficha- columna 
    acquire_screen();
    
    rect( screen, ORIGEN_X+columna*DISTANCIA_COLS, ORIGEN_Y+fila*DISTANCIA_FILAS, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS , makecolor2(color));  
    rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+1, ORIGEN_Y+fila*DISTANCIA_FILAS+1, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-1,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -1, makecolor2(color));  
    rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+2, ORIGEN_Y+fila*DISTANCIA_FILAS+2, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-2,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -2, makecolor2(color));
    rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+3, ORIGEN_Y+fila*DISTANCIA_FILAS+3, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-3,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -3, makecolor2(color));  
    //textout_ex( screen, font, cad,  560,10 , makecol( 255, 0, 0), makecol(0, 0, 0));  
     
    release_screen();
	
}




void TEntornoDesactivarCasilla(int fila, int columna, int color=COLOR_BLANCO) {

 
// Pinta de trazo distinto la ficha- columna 
  acquire_screen();

  rect( screen, ORIGEN_X+columna*DISTANCIA_COLS, ORIGEN_Y+fila*DISTANCIA_FILAS, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS , makecolor2(color));    
  rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+1, ORIGEN_Y+fila*DISTANCIA_FILAS+1, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-1,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -1, makecol(0,0,0));
  rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+2, ORIGEN_Y+fila*DISTANCIA_FILAS+2, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-2,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -2, makecol(0,0,0));  
  rect( screen, ORIGEN_X+columna*DISTANCIA_COLS+3, ORIGEN_Y+fila*DISTANCIA_FILAS+3, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-3,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS -3, makecol(0,0,0));  
  release_screen();
 

}


void TEntornoEliminarCasilla(int fila, int columna) {

  rectfill( screen, ORIGEN_X+columna*DISTANCIA_COLS+1, ORIGEN_Y+fila*DISTANCIA_FILAS+1, ORIGEN_X+columna*DISTANCIA_COLS +DISTANCIA_COLS-1,ORIGEN_Y+fila*DISTANCIA_FILAS+DISTANCIA_FILAS-1 , makecol( 0, 0, 0));   
}


// Establece la ficha en función de su tipo
void TEntornoPonerCasilla(int fila, int columna,  int valor) {
  
   
    acquire_screen();
    // recupera el gráfico del vector de fichas la ficha que corresponde.
    draw_sprite( screen, fichas[valor],ORIGEN_X+columna*DISTANCIA_COLS + 3 , ORIGEN_Y+fila*DISTANCIA_FILAS +3);
    release_screen();
    
   
}

// Muestra una cadena de 15 caracteres
void TEntornoMostrarMensaje(char *c){
  textout_ex( screen, font, "                                        ",  600,570 , makecol( 255, 0, 0), makecol(0, 0, 0));  
   
  textout_ex( screen, font, "Información:",  600,530 , makecol( 255, 255, 0), makecol(0, 0, 0));  
  textout_ex( screen, font, c,  600,550 , makecol( 255, 255, 0), makecol(0, 0, 0));  
}

// Muestra una cadena de 15 caracteres
void TEntornoMostrarPuntos(int puntos){
  char cad[20];
  sprintf(cad, "PUNTOS: %8d",puntos);  
  textout_ex( screen, font, cad,  600,500 , makecol( 255, 255, 255), makecol(0, 0, 0));  
  
}


TipoTecla TEntornoLeerTecla(void)
{

	TipoTecla tecla=TNada;
	readkey();
	
	if (key[KEY_UP]) tecla=TArriba;
	else if (key[KEY_DOWN]) tecla=TAbajo;
	else if (key[KEY_RIGHT]) tecla=TDerecha;
	else if (key[KEY_LEFT]) tecla=TIzquierda;
	else if (key[KEY_ENTER]) tecla=TEnter;
	else if (key[KEY_ESC]) tecla=TSalir;
	
	clear_keybuf();
	return tecla;

}

void TEntornoTerminar(){
  for (int i=0;i<MAX_FICHAS;i++)
     if (fichas[i]!=NULL)
      destroy_bitmap( fichas[i]);
  
}


void TEntornoPausar(unsigned int milisegundo){
  usleep(milisegundo);
}

