#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
			case 0: //INICIALIZAR
			break;
			case 1:	//JUGAR	
			break;
			case 2: //SALIR
				salirJuego = true;
			break;
		};
		switch(estado){

			case Estado::ESTADO_INICIANDO: 
			break;

			case Estado::ESTADO_JUGANDO:
			break;
			case Estado::ESTADO_TERMINANDO: 
			break;
			};

		salirJuego = true;

			}
			return true;
}
