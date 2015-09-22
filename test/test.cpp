
#include "unittests.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include<SDL.h>
#else
#ifdef WINDOWS
#include "SDL2/include/SDL.h"
#else
#include<SDL/SDL.h>
#endif
#endif

using namespace std;
SDL_Renderer *renderer = NULL;
SDL_Window *win = NULL;

void render_func(void) {
}

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Hello World", 0, 0, 256, 256, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

//	screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

#ifdef TEST_SDL_LOCK_OPTS
	EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
	UnitTests unit;
	unit.run();
#ifdef EMSCRIPTEN
	emscripten_set_main_loop(render_func, 60, 1);
#endif
	SDL_Quit();

	return 0;
}

