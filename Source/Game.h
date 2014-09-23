#include <SDL.H>
#include <SDL_image.h>

class CGame
{
public:
	
	enum Estado{ESTADO_INICIANDO,ESTADO_MENU,ESTADO_JUGANDO,ESTADO_TERMINANDO,ESTADO_FINALIZANDO};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	void Iniciando();
	SDL_Surface *screen;


	Estado estado;


};	