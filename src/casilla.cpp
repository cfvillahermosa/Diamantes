/**
ELEMENTOS DE PROGRAMACIÓN
Curso 2009/10

Nombre: CASILLA.CPP
Descripción: Especificación del TAD Casilla para el proyecto DIAMANTE
	     Almacena y manipula los datos de una casilla del tablero del juego 
Autor:       Profesores de la asignatura
Fecha de creación:	2/12/2009
Fecha de última modificación: 2/12/2009
*/

#include "casilla.h"


casilla crearCasilla(){
    casilla c;
    c.vacia=true;
	return c;
}

void colorearCasilla(casilla &c, int _color) {
     c.color = _color;   
     c.vacia = false;  
}


void vaciarCasilla (casilla &c){
     c.vacia = true;
}

int queColorCasilla(casilla c){
     return c.color;
}

bool esVaciaCasilla (casilla c){
     return c.vacia;
}
