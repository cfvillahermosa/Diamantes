#include "entorno.h"

void seleccionar(int y, int x) {
  if (y>=0 && x>=0 && y< MAX_TAMANIO && x<MAX_TAMANIO)
    TEntornoActivarCasilla(y,x,COLOR_NARANJA);	
}

int main(){
  int x=0, y=0;
  bool salir=false;
  TipoTecla tecla=TNada;
  int lado, nfila, fichas;
  bool aleat;
  int datos[MAX_TAMANIO][MAX_TAMANIO];
  
  srand(time(NULL)); // Inicializa el generador de números aleatorios
  
  //carga la configuración desde el archivo de configuración
  TEntornoCargarConfiguracion(lado,fichas,nfila,aleat, datos);
  
  TEntornoIniciarPantalla (MAX_TAMANIO,MAX_FICHAS);
  TEntornoActivarCasilla(0,0,COLOR_ROJO);
  TEntornoMostrarMensaje("zona de mensajes");
  
  // Establecer una ficha de tipo 2
  TEntornoPonerCasilla(3,3, 2) ;
  
  
  // Inicializar el tablero de forma aleatoria
  for (int i=0;i<MAX_TAMANIO;i++)
    for (int j=0;j<MAX_TAMANIO;j++)
      TEntornoPonerCasilla(i, j, (rand()%(MAX_FICHAS-1))) ;
       
  //Elimina una celda del tablero  
  TEntornoEliminarCasilla(1,8);
  
  //Lee las teclas pulsadas y las procesa hasta pulsar la tecla ESCAPE
  while(!salir){
    tecla=TEntornoLeerTecla();  
    switch (tecla) {
      case TDerecha:  if (x<MAX_TAMANIO-1) {
	TEntornoDesactivarCasilla(y,x,COLOR_BLANCO);
	x++;      
	TEntornoActivarCasilla(y,x,COLOR_ROJO);
      }		
      break;
      
      case TIzquierda:if (x>0) {
			  TEntornoDesactivarCasilla(y,x,COLOR_BLANCO);
			  x--;      
			  TEntornoActivarCasilla(y,x,COLOR_ROJO);
			}
			break;
      
      case TArriba:   if (y>0) {TEntornoDesactivarCasilla(y,x,COLOR_BLANCO);
			  y--;      
			  TEntornoActivarCasilla(y,x,COLOR_ROJO);
		       }
		       break;
			  
      case TAbajo:     if (y<MAX_TAMANIO-1) { TEntornoDesactivarCasilla(y,x,COLOR_BLANCO);
			      y++;      
			      TEntornoActivarCasilla(y,x,COLOR_ROJO);
		       }
		       break;
      
      case TEnter:     	seleccionar(y+1,x);  //seleccionar es una función auxiliar para rebordear una celda de cólor naranja
			seleccionar(y-1,x);
			seleccionar(y,x-1);
			seleccionar(y,x+1);
			TEntornoActivarCasilla(y,x,COLOR_ROJO);
			break;
			  
      case TSalir: salir=true; 
    }
    
  }    
  
  TEntornoTerminar();    
  return 0;
  
} 
END_OF_MAIN();



