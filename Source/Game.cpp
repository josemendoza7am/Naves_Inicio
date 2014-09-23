#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.H>
#include <SDL_image.h>

CGame::CGame(){
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
	
		switch(estado){

			case Estado::ESTADO_INICIANDO: 
			break;

			case Estado::ESTADO_JUGANDO:
			break;
			case Estado::ESTADO_TERMINANDO: 
			break;
			};

		salirJuego = true;
		SDL_Flip(screen);

			}
			return true;

			if (SDL_Init( SDL_INIT_VIDEO )){

printf("Error %s ", SDL_GetError());

exit(EXIT_FAILURE);

}

screen = SDL_SetVideoMode( 640, 480, 24, SDL_SWSURFACE );

if (screen == NULL){

printf("Error %s ", SDL_GetError());

exit(EXIT_FAILURE);

}

SDL_WM_SetCaption( "Mi primer Juego", NULL );
}
