#include "casilla.h"
#include "entorno.h"
using namespace std;
const int MAX=10;
typedef int matriz_enteros[MAX][MAX];
typedef casilla matriz[MAX][MAX];
typedef struct tablero{
	matriz M;
	int tam_real;
};


void creartableroaleatorio (tablero & T,int lado,int numcolores);
void creartablero (tablero & T,int lado, int numcolores);
void ponercasillatablero (tablero & T, int f, int c,int color);
void intercambiardoscasillas(tablero & T,int f1,int c1,int f2,int c2);
void obtenercasilla (tablero T, int f,int c,bool & vacia, int & color);
bool sivaciacasilla(tablero T,int f,int c);
int tamaniorealtablero(tablero T);
int devolverceldasmismocolorhorizontal ( tablero T, int f, int c);
int devolverceldasmismocolorvertical (tablero T, int f, int c);
void eliminarcasillashorizontal ( tablero & T, int f, int c, int numcasillas);
void eliminarcasillasvertical ( tablero & T, int f, int c, int numcasillas);
void desplazarceldashorizontal (tablero & T, int f , int c, int numcasillas);
void desplazarceldasvertical (tablero & T, int f, int c, int numcasillas);
bool sihaylineahorizontal (tablero T,int f,int c,int longitudlinea);
bool sihaylineavertical (tablero T,int f,int c,int longitudlinea);
void devolverposiciontablero(tablero T, int longitudlinea, int & posicionfila, int & posicioncolumna,bool & finalizado);

