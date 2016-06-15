/**
ELEMENTOS DE PROGRAMACIÓN
Curso 2009/10

Nombre: CASILLA.H
Descripción: Especificación del TAD Casilla para el proyecto DIAMANTE
	     Almacena y manipula los datos de una casilla del tablero del juego 
Autor:       Profesores de la asignatura
Fecha de creación:	2/12/2009
Fecha de última modificación: 2/12/2009
*/
#ifndef TADCASILLA_H
#define TADCASILLA_H

typedef struct casilla {
        bool vacia;  // indica si la casilla est� vac�a o no
        int color;   // si la casilla no est� vac�a, indica el color (de 0 a 5)
};

/**
PRE: 
POST: Devuelve una casilla inicializada a vacia.
Complejidad: O(1)
*/
casilla crearCasilla();

/**
PRE: c es una casilla válida y _valor corresponde a un color válido (de 0 a 5)
POST: Establece el valor de la casilla c con el valor pasado por parámetros. 
Devuelve la casilla modificada no vac�a.
Complejidad: O(1)
*/
void colorearCasilla(casilla &c, int _color);


/**
PRE: c es una casilla válida 
POST: Establece la casilla vac�a
Complejidad: O(1)
*/
void vaciarCasilla (casilla &c);

/**
PRE: c es una casilla válida no vac�a.
POST: Devuelve el color de la casilla c (de 0 a 5)
Complejidad: O(1)
*/
int queColorCasilla(casilla c);

/**
PRE: c es una casilla válida.
POST: Devuelve si la casilla c est� vac�a o no
Complejidad: O(1)
*/
bool esVaciaCasilla (casilla c);

#endif