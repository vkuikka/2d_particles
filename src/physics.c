#include "sim.h"

void	clear_grid(e_particle grid[SIM_SIZE][SIM_SIZE])
{
	for (int x = 0; x < SIM_SIZE; x++)
	{
		for (int y = 0; y < SIM_SIZE; y++)
		{
			if (grid[x][y] == APPEARING_WATER)
				grid[x][y] = WATER;
			else if (grid[x][y] == APPEARING_LAVA)
				grid[x][y] = LAVA;
			else if (grid[x][y] != SAND &&
					grid[x][y] != WATER &&
					grid[x][y] != STONE &&
					grid[x][y] != VOID &&
					grid[x][y] != LAVA)
				grid[x][y] = EMPTY;
		}
	}
}

int	move_down(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	if (v.y > 0 && s[v.x][v.y - 1] == EMPTY)
	{
		s[v.x][v.y - 1] = s[v.x][v.y];
		s[v.x][v.y] = EMPTY;
		return (1);
	}
	return (0);
}

static void	clear_around_void(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (x == 0 && y == 0)
				continue;
			if (v.x + x >= 0 && v.x + x < SIM_SIZE &&
				v.y + y >= 0 && v.y + y < SIM_SIZE &&
				s[v.x + x][v.y + y] != VOID)
				s[v.x + x][v.y + y] = EMPTY;
		}
	}
}

void	physics(t_world *world)
{
	t_ivec2					v;

	v.x = -1;
	while (++v.x < SIM_SIZE)
	{
		v.y = -1;
		while (++v.y < SIM_SIZE)
		{
			if ((world->sim[v.x][v.y] == SAND ||
				world->sim[v.x][v.y] == WATER ||
				world->sim[v.x][v.y] == LAVA) && rand() % 5)
			{
				if (!move_down(world->sim, v))
				{
					if (world->sim[v.x][v.y] == SAND)
						move_side_sand(world->sim, v);
					if (world->sim[v.x][v.y] == WATER)
						move_side_water(world->sim, v);
					if (world->sim[v.x][v.y] == LAVA)
						move_side_lava(world->sim, v);
				}
			}
			else if (world->sim[v.x][v.y] == VOID)
				clear_around_void(world->sim, v);
		}
	}
	clear_grid(world->sim);
}
