#include <SDL.h>;
#include "Objeto.h"
#include "nave.h"
#include "Stage.h"
class CGame
{
public:
	bool Start();
	static CGame instanceGame;
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_PRE_JUGANDO,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	CGame();
	void Finalize();

private:
	void Iniciando();
	void Menu();
	void MoverEnemigo();
	bool EsLimitePantalla(Objeto * objeto, int bandera);

	int opcionSeleccionada;
	Uint8 *keys; //Esta variable servirá para ver si determinadas teclas están o no pulsadas
	SDL_Event event; // La variable event de tipo evento de SDL servirá para monitorizar el teclado

	SDL_Surface * screen;

	Nave * nave;
	Nave *enemigoArreglo [10];
	stage nivel[4];
	void InicializandoStage();
	int NivelActual;
	
	Objeto *menu;//Fondo del menu 
	Objeto *textos;//textos del juego
	Objeto *fondo;//fondo del juego

	

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;

	Estado estado;
};