#include "../sim.h"

static void move_lava(int x, int y, e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	int		tmp;

	if (s[v.x + x][v.y + y] == STONE)
	{
		s[v.x][v.y] = STONE;
		if (!(rand() % 2))
			s[v.x + x][v.y + y] = EMPTY;
		else
			s[v.x + x][v.y + y] = APPEARING_LAVA;
	}
	else if (s[v.x + x][v.y + y] == WATER)
	{
		s[v.x][v.y] = EMPTY;
		s[v.x + x][v.y + y] = STONE;
	}
	else
	{
		tmp = s[v.x + x][v.y + y];
		s[v.x + x][v.y + y] = APPEARING_LAVA;
		s[v.x][v.y] = tmp;
	}
}

int		move_side_lava(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	int		left;
	int		right;

	if (v.x > 0 && v.y > 2)
		left = s[v.x - 1][v.y - 1] != LAVA && s[v.x - 1][v.y - 1] != SAND;
	else
		left = 0;

	if (v.x < SIM_SIZE - 1 && v.y > 2)
		right = s[v.x + 1][v.y - 1] != LAVA && s[v.x + 1][v.y - 1] != SAND;
	else
		right = 0;
	if (left && right)
	{
		if (rand() % 2)
			left = 0;
		else 
			right = 0;
	}
	if (left)
		move_lava(-1, -1, s, v);
	else if (right)
		move_lava(1, -1, s, v);
	else
	{
		left = v.x > 0 && s[v.x - 1][v.y] != LAVA;
		right = v.x < SIM_SIZE - 1 && s[v.x + 1][v.y] != LAVA;
		if (left)
			move_lava(-1, 0, s, v);
		else if (right)
			move_lava(1, 0, s, v);
	}
	return (1);
}
