#include "tablero.h"
#include <cstdlib>


void creartableroaleatorio (tablero & T,int lado,int numcolores){
	
	int i,j;
	T.tam_real=lado;
	for(i=0;i<T.tam_real;i++)
		for(j=0;j<T.tam_real;j++){
		T.M[i][j]=crearCasilla();
		colorearCasilla(T.M[i][j], rand()% numcolores);
		}
}


void creartablero (tablero & T,int numcolores, int lado){
	matriz_enteros datos;
	int nflinea;
	bool aleatorio;
	TEntornoCargarConfiguracion(lado, numcolores, nflinea, aleatorio,datos);
	
}


void ponercasillatablero (tablero & T, int f, int c,int color){
	
	colorearCasilla(T.M[f][c], color);	
}


void intercambiardoscasillas(tablero & T,int f1,int c1,int f2,int c2){
	int colorcas1;
	int colorcas2;
	bool vacia1;
	bool vacia2;
	colorcas1=queColorCasilla(T.M[f1][c1]);
	colorcas2=queColorCasilla(T.M[f2][c2]);	
	
	vacia1=esVaciaCasilla (T.M[f1][c1]);
	vacia2=esVaciaCasilla (T.M[f2][c2]);
	
	T.M[f1][c1].color=colorcas2;
	T.M[f1][c1].vacia=vacia2;
	
	T.M[f2][c2].color=colorcas1;
	T.M[f2][c2].vacia=vacia1;
	
}
	




void obtenercasilla (tablero T, int f,int c,bool & vacia, int & color){
	color=queColorCasilla(T.M[f][c]);
	vacia=esVaciaCasilla (T.M[f][c]);
	
}


bool sivaciacasilla(tablero T,int f,int c){
	bool sabersivacia;
	sabersivacia=esVaciaCasilla (T.M[f][c]);
	return sabersivacia;
}


int tamaniorealtablero(tablero T){
	return T.tam_real;
}


int devolverceldasmismocolorhorizontal ( tablero T, int f, int c){
	bool vacia;
	int colorinicial;
	colorinicial=queColorCasilla(T.M[f][c]);
	int cont;
	bool enc1;
	bool enc2;
	int j;
	cont=0;
	enc1=false;
	while(!enc1){
		for(j=c+1;j<T.tam_real;j++){
			if(queColorCasilla(T.M[f][j])==colorinicial){
				cont++;
			}
			else
				enc1=true;
		}
	}
	enc2=false;
	while(!enc2){
		for(j=c-1;j>=0;j--){
			if(queColorCasilla(T.M[f][j])==colorinicial){
				cont++;
			}
			else
				enc2=true;
		}
	}
	return cont;
}

int devolverceldasmismocolorvertical (tablero T, int f, int c){
	int colorinicial;
	colorinicial=queColorCasilla(T.M[f][c]);
	int cont;
	bool enc1;
	bool enc2;
	int i;
	cont=0;
	enc1=false;
	while(!enc1){
		for(i=f-1;f>0;f--){
			if(queColorCasilla(T.M[i][c])==colorinicial){
				cont++;
			}
			else
				enc1=true;
		}
	}
	enc2=false;
	while(!enc2){
		for(i=f+1;i<T.tam_real;i++){
			if(queColorCasilla(T.M[i][c])==colorinicial){
				cont++;
			}
			else
				enc2=true;
		}
	}
	return cont;			
}


void eliminarcasillashorizontal ( tablero & T, int f, int c, int numcasillas){
	numcasillas=devolverceldasmismocolorhorizontal(T,f,c);
	int borradas;
	int colorinicial;
	colorinicial=queColorCasilla(T.M[f][c]);
	bool enc1;
	bool enc2;
	int j;
	borradas=0;
	
	while(borradas!=numcasillas){
		enc1=false;
		while(!enc1){
			for(j=c;j<T.tam_real;j++){
				if(queColorCasilla(T.M[f][j])==colorinicial){
					vaciarCasilla (T.M[f][j]);
					borradas++;
				}
				else
					enc1=true;
			}
		}
		enc2=false;
		while(!enc2){
			for(j=c-1;j>=0;j--){
				if(queColorCasilla(T.M[f][j])==colorinicial){
					vaciarCasilla (T.M[f][j]);
					borradas++;
				}
				else
					enc2=true;
			}
		}
	}
}
	
	
void eliminarcasillasvertical ( tablero & T, int f, int c, int numcasillas){
	numcasillas=devolverceldasmismocolorhorizontal(T,f,c);
	int borradas;
	int colorinicial;
	colorinicial=queColorCasilla(T.M[f][c]);
	bool enc1;
	bool enc2;
	int i;
	borradas=0;
		
	while(borradas!=numcasillas){
		enc1=false;
		while(!enc1){
			for(i=f;f>0;f--){
				if(queColorCasilla(T.M[i][c])==colorinicial){
					vaciarCasilla(T.M[i][c]);
					borradas++;
				}
				else
					enc1=true;
			}
		}
		enc2=false;
		while(!enc2){
			for(i=f+1;i<T.tam_real;i++){
				if(queColorCasilla(T.M[i][c])==colorinicial){
					vaciarCasilla(T.M[i][c]);
					borradas++;
				}
				else
					enc2=true;
			}
		}
	}
}

void desplazarceldashorizontal (tablero & T, int f , int c, int numcasillas){
	int i;
	int aux;
	int cont;
	aux=c;
	for(i=f-1;i>=0;i--){
		cont=0;
		aux=c;
		while(cont<numcasillas){
			T.M[i][aux]=T.M[i+1][aux];
			cont++;
			aux++;
			f--;
		}
	}
}

void desplazarceldasvertical (tablero & T, int f, int c, int numcasillas){
	int i;
	int aux;
	aux=f-1;
 	for(i=f-(numcasillas+1);i>=0;i--){
		T.M[i][c]=T.M[aux][c];
		aux--;
	}

}

bool sihaylineahorizontal (tablero T,int f,int c,int longitudlinea){
	bool linea;
	linea=false;
	if(devolverceldasmismocolorhorizontal ( T, f, c)==longitudlinea){
		linea=true;
	}
	return linea;
}


bool sihaylineavertical (tablero T,int f,int c,int longitudlinea){
	bool linea;
	linea=false;
	if(devolverceldasmismocolorvertical ( T, f, c)==longitudlinea){
		linea=true;
	}
	return linea;
}

void devolverposiciontablero(tablero T, int longitudlinea, int & posicionfila, int & posicioncolumna,bool & finalizado){
	int i;
	int j;
	bool enc;
	finalizado=false;
	enc=false;
	for(i=0;i<T.tam_real;i++){
		for(j=0;j<T.tam_real;j++){
			while(!enc){
				if (sihaylineahorizontal(T,i,j,longitudlinea)){
					enc=true;
					posicionfila=i;
					posicioncolumna=j;
				}
			}	
		}
	}
	if(!enc)
		finalizado=true;
}
	



	
				
				
				


















