#include "../sim.h"

static void	sand_movable_tiles(int *left, int *right, e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	if (v.x > 0 && v.y > 1)
		*left = s[v.x - 1][v.y - 1] == WATER || s[v.x - 1][v.y - 1] == EMPTY;
	else
		*left = 0;
	if (v.x < SIM_SIZE - 1 && v.y > 1)
		*right = s[v.x + 1][v.y - 1] == WATER || s[v.x + 1][v.y - 1] == EMPTY;
	else
		*right = 0;
	if (*left && *right)
	{
		if (rand() % 2)
			*left = 0;
		else 
			*right = 0;
	}
}

int		move_side_sand(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	int		tmp;
	int		left;
	int		right;

	sand_movable_tiles(&left, &right, s, v);
	if (left)
	{
		tmp = s[v.x - 1][v.y - 1];
		s[v.x - 1][v.y - 1] = s[v.x][v.y];
		s[v.x][v.y] = tmp;
		return (1);
	}
	else if (right)
	{
		tmp = s[v.x + 1][v.y - 1];
		s[v.x + 1][v.y - 1] = s[v.x][v.y];
		s[v.x][v.y] = tmp;
		return (1);
	}
	return (0);
}
