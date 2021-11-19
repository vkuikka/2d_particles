#include "sim.h"

static void		fill_sim(t_world *world)
{
	int		x;
	int		y;

	x = 0;
	while (x < SIM_SIZE)
	{
		y = 1;
		while (y < SIM_SIZE)
		{
			world->sim[x][y] = world->addition;
			y++;
		}
		x++;
	}
}

static void		mouse_input(t_world *world)
{
	static t_ivec2	mouse;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	for (int x = -10; x < 10; x++)
		for (int y = -10; y < 10; y++)
		{
			int new_x = mouse.x + x;
			int new_y = RES_Y - (mouse.y + y);
			new_x /= RES_SCALE;
			new_y /= RES_SCALE;
			if (new_x < SIM_SIZE && new_x >= 0 &&
				new_y < SIM_SIZE && new_y >= 0)
				world->sim[new_x][new_y] = world->addition;
		}
}

static void		keyboard_input(SDL_Event event, t_world *world)
{
	if (event.key.repeat == 0)
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_1)
			world->addition = EMPTY;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_2)
			world->addition = SAND;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_3)
			world->addition = WATER;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_4)
			world->addition = STONE;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_5)
			world->addition = LAVA;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_6)
			world->addition = VOID;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_C)
			fill_sim(world);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
			world->shift_down = 1;
		else if (event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
			world->shift_down = 0;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			world->pause = 1;
		else if (event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			world->pause = 0;
	}
}

void	input(t_world *world)
{
	SDL_Event	event;

	if (world->shift_down)
		mouse_input(world);
	while (SDL_PollEvent(&event))
	{
		keyboard_input(event, world);
		if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit(0);
	}
}