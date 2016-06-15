/**
ELEMENTOS DE PROGDRAMACIÓN
Curso 2009/2010

Nombre: ENTORNO.H
Descripción: Especificación del TAD Entorno para el proyecto DIAMANTES
	     Encargado del manejo de la interfaz del juego
Autor:       Profesores de la asignatura
Fecha de creación:	18/11/2010

*/


#include <allegro.h>
// -------------------------------------------------------------
// Definicion de constantes necesarias en tablero.h
// -------------------------------------------------------------

#ifndef Constantes
#define Constantes
const int MAX_TAMANIO=10;
const int MAX_FICHAS=6;
#endif

// Constantes para la identificación de distintos colores
const int COLOR_BLANCO=0; // BLANCO
const int COLOR_ROJO=1; //ROJO - para el cursor
const int COLOR_NARANJA=2; // para color naranja
const int COLOR_AMARILLO=3; // para color naranja
const int COLOR_VERDE=4; // para color naranja


// -------------------------------------------------------------
// Definicion de tipos enumerados
// -------------------------------------------------------------
/**
	 Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
	 de los cursores que se ha pulsado
*/
typedef enum TipoTecla {TNada, TIzquierda, TDerecha, TArriba, TAbajo, TSalir, TEnter};

/**
PRE: 1<=tamanio<=MAX_TAMANIO,
POST: Inicia la pantalla de juego, incluyendo una rejilla cuadrada de tamanio
*/
void TEntornoIniciarPantalla (int tamanio, int nfichas) ;

/**
PRE: 
POST: Devuelve verdadero si se carga correctamente la configuración del juego, 
falso en caso contrario. Si la configuración se lee de forma correcta se devolverá 
el tamaño de juego, el número de tipos de fichas o figuras a utilizar, 
número mínimo de fichas para formar línea, si datos para inicializar las fichas serán
aleatorios o bien vendrán definidos en el parámetros datos.

Por defecto, el archivo diamante.cnf se encuentra en el directorio  [proyecto]/debug/src.
 */
bool TEntornoCargarConfiguracion(int &tamanio, int &fichas, int &nflinea, bool &aleatorio, int datos[MAX_TAMANIO][MAX_TAMANIO]);


/**
PRE: fila y columna son coordenadas válidas en el entorno. Valores para color: COLOR_BLANCO, COLOR_ROJO, COLOR_AMARILLO, COLOR_NARANJA, COLOR_VERDE
POST: Establece una casilla con coordenadas fila, columna el color pasado por parámetros, la correspondiente casilla quedará activa en un rectángulo rojo. 
*/
void TEntornoActivarCasilla(int fila, int columna, int color);


/**
PRE: fila y columna son coordenadas válidas en el entorno. Valores para color: COLOR_BLANCO, COLOR_ROJO, COLOR_AMARILLO, COLOR_NARANJA, COLOR_VERDE
POST: Establece una casilla con coordenadas fila, columna en su estado habitual, sin resaltar.
*/
void TEntornoDesactivarCasilla(int fila, int columna, int color);

/**
PRE: fila y columna son coordenadas válidas en el tablero
POST: Elimina del entorno el valor que existe en la casilla cuyas coordenadas son fila, columna.
*/
void TEntornoEliminarCasilla(int fila, int columna);


/** 
  PRE: El módulo recibe las coordenadas (fila, columna) correctas de una casilla, así como el tipo de ficha (0,1,2,...MAX_FICHAS-1)
  POST: Establece en el entorno el valor de una casilla colocada en la posición fila, columna del tablero. Este valor se presentará el color de la ficha. 
 */
void TEntornoPonerCasilla(int fila, int columna, int color);


/**
PRE: El módulo recibe una cadena de caracteres, un mensaje.
POST:Escribe el mensaje pasado por parámetros en el entorno, concretamente, en el área de mensajes.
*/
void TEntornoMostrarMensaje(char *c);

/**
PRE: El módulo recibe por parámetros los puntos acumulados en la partida
POS: Escribe en la zona de puntos los puntos acumulados por el jugador
*/
void TEntornoMostrarPuntos(int puntos);

/**
PRE:
POST:Devuelve un valor enumerado de TipoTecla con la tecla que se ha pulsado y que se deben interpretar.
*/
TipoTecla TEntornoLeerTecla(void);
	
/**
PRE:
POST: Destruye el contexto del entorno gráfico.
*/
void TEntornoTerminar();

/**
PRE: Recibe por parámetros el un número de miliseguntos
POST:  Permite pausar la ejecución del entorno un número de milisegundos pasados por parámetros
*/
void TEntornoPausar(unsigned int milisegundo);

