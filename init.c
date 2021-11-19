#include "sim.h"

static SDL_Texture	*empty_texture(SDL_Renderer *renderer)
{
	SDL_Texture	*texture;

	texture = NULL;
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STREAMING, RES_X, RES_Y);
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderTarget(renderer, NULL);
	return (texture);
}

void	init_window(t_window **window)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
		ft_error("could not initialize SDL\n");
	*window = (t_window *)malloc(sizeof(t_window));
	if (!*window)
		ft_error("memory allocation failed\n");
	window[0]->SDLwindow = SDL_CreateWindow("SIM",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			RES_X, RES_Y, SDL_WINDOW_ALLOW_HIGHDPI);
	if (!window[0]->SDLwindow)
		ft_error("could not create window");
	window[0]->SDLrenderer
		= SDL_CreateRenderer(window[0]->SDLwindow, -1, 0);
	if (!window[0]->SDLrenderer)
		ft_error("could not create renderer");
	window[0]->texture = empty_texture(window[0]->SDLrenderer);
	window[0]->frame_buffer = NULL;
}

void	init_world(t_world **world)
{
	*world = (t_world*)malloc(sizeof(t_world));
	if (!world)
		ft_error("could not allocate world");
	for (int x = 0; x < SIM_SIZE; x++)
		for (int y = 0; y < SIM_SIZE; y++)
			world[0]->sim[x][y] = EMPTY;
	world[0]->addition = SAND;
}

