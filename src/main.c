#include "sim.h"

void	draw_area(t_window *window, t_world *world, int x, int y)
{
	for (int i = 0; i < RES_SCALE; i++)
		for (int j = 0; j < RES_SCALE; j++)
		{
			int new_x = x * RES_SCALE + i;
			int new_y = y * RES_SCALE + j;
			if (new_x < RES_X && new_y <= RES_Y && new_x >= 0 && new_y > 0)
			{
				if (world->sim[x][y] == WATER)
					window->frame_buffer[new_x + (RES_Y - new_y) * RES_X] = COLOR_WATER;
				else if (world->sim[x][y] == SAND)
					window->frame_buffer[new_x + (RES_Y - new_y) * RES_X] = COLOR_SAND;
				else if (world->sim[x][y] == STONE)
					window->frame_buffer[new_x + (RES_Y - new_y) * RES_X] = COLOR_STONE;
				else if (world->sim[x][y] == LAVA)
					window->frame_buffer[new_x + (RES_Y - new_y) * RES_X] = COLOR_LAVA;
				else if (world->sim[x][y] == VOID)
					window->frame_buffer[new_x + (RES_Y - new_y) * RES_X] = COLOR_VOID;
			}
		}
}

void	simple_draw(t_window *window, t_world *world)
{
	for (int x = 0; x < SIM_SIZE; x++)
		for (int y = 0; y < SIM_SIZE; y++)
			if (world->sim[x][y] != EMPTY)
				draw_area(window, world, x, y);
}

void	render(t_window *window, t_world *world)
{
	if (SDL_LockTexture(window->texture, NULL,
			(void **)&window->frame_buffer, &(int){0}) != 0)
		ft_error("failed to lock texture\n");
	ft_memset(window->frame_buffer, 0, RES_X * RES_Y * sizeof(int));
	if (!world->pause)
	{
		physics(world);
		physics(world);
	}
	simple_draw(window, world);
	SDL_UnlockTexture(window->texture);
	SDL_RenderCopy(window->SDLrenderer, window->texture, NULL, NULL);
	SDL_RenderPresent(window->SDLrenderer);
	SDL_RenderClear(window->SDLrenderer);
}

void	set_window_title(t_window *window, t_world *world)
{
	if (world->addition == WATER)
		SDL_SetWindowTitle(window->SDLwindow, "Water");
	else if (world->addition == SAND)
		SDL_SetWindowTitle(window->SDLwindow, "Sand");
	else if (world->addition == STONE)
		SDL_SetWindowTitle(window->SDLwindow, "Stone");
	else if (world->addition == LAVA)
		SDL_SetWindowTitle(window->SDLwindow, "Lava");
	else if (world->addition == EMPTY)
		SDL_SetWindowTitle(window->SDLwindow, "Remove");
	else if (world->addition == VOID)
		SDL_SetWindowTitle(window->SDLwindow, "Void");
}

int	main(void)
{
	t_window	*window;
	t_world		*world;

	init_window(&window);
	init_world(&world);
	while (1)
	{
		input(world);
		render(window, world);
		set_window_title(window, world);
	}
}
