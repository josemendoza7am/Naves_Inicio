#include <SDL.H>
#include <SDL_image.h>
#include "Nave.h"
#include <SDL.h>

class CGame
{
public:
	bool Start();
	static CGame instanceGame;
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	CGame();
	void Finalize();

private:
	void Iniciando();
	Uint8 * keys;
	SDL_Event event;
	SDL_Surface *screen;
	Nave * nave;
	Estado estado;
};