#include<iostream>
#include "engine/engine.h"

#ifdef __EMSCRIPTEN__
#include<SDL.h>
#include<emscripten.h>
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
	//if (SDL_MUSTLOCK(renderer)) SDL_LockSurface(renderer);
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
	}
	static int off = 0;
	SDL_Rect r;
	r.w = 16;
	r.h = 16;
	for (int i = 0; i < 16; i++) {
		r.x = i*16;
		for (int j = 0; j < 16; j++) {
			r.y = j*16;
#ifdef TEST_SDL_LOCK_OPTS
			// Alpha behaves like in the browser, so write proper opaque pixels.
			int alpha = 255;
#else
			// To emulate native behavior with blitting to screen, alpha component is ignored. Test that it is so by outputting
			// data (and testing that it does get discarded)
			int alpha = (i+j) % 255;
#endif
			SDL_SetRenderDrawColor(renderer, 0, 0, (i+off)%255, 255);
			SDL_RenderFillRect(renderer, &r);
			//renderer->
			//*((Uint32*)renderer->pixels + i * 256 + j) = SDL_MapRGBA(renderer->format, i + off, j + off*2, 255-i, alpha);
		}
	}
	off++;
	//if (SDL_MUSTLOCK(renderer)) SDL_UnlockSurface(renderer);
	SDL_RenderPresent(renderer);
}

int main()
{
	cout << "Hello World!" << endl;
	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Hello World", 0, 0, 256, 256, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

//	screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

#ifdef TEST_SDL_LOCK_OPTS
	EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
#ifdef EMSCRIPTEN
	emscripten_set_main_loop(render_func, 60, 1);
#endif
	SDL_Quit();

	return 0;
}

