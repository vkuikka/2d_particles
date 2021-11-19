#include "../sim.h"

static void move_water(int x, int y, e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	if (s[v.x + x][v.y + y] == LAVA)
		s[v.x + x][v.y + y] = DISAPPEARING;
	else
		s[v.x + x][v.y + y] = APPEARING_WATER;
	if (x || y)
		s[v.x][v.y] = DISAPPEARING;
}

int		move_side_water(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v)
{
	e_particle	tmp;
	int	move_left;
	int	move_right;
	int	right_limit = rand() % 6;
	int	left_limit = -(rand() % 6);
	int	i;

	move_right = 0;
	i = 1;
	while (i < right_limit && v.x + i < SIM_SIZE)
	{
		tmp = s[v.x + i][v.y];
		if (tmp == EMPTY)
			move_right = i;
		else if (tmp != WATER && tmp != DISAPPEARING && tmp != APPEARING_WATER)
			break ;
		i++;
	}
	move_left = 0;
	i = -1;
	while (i > left_limit && v.x + i >= 0)
	{
		tmp = s[v.x + i][v.y];
		if (tmp == EMPTY)
			move_left = i;
		else if (tmp != WATER && tmp != DISAPPEARING && tmp != APPEARING_WATER)
			break ;
		i--;
	}
	if (move_left && move_right)
	{
		if (rand() % 2)
			move_left = 0;
		else 
			move_right = 0;
	}
	if (move_right)
		move_water(move_right, 0, s, v);
	if (move_left)
		move_water(move_left, 0, s, v);
	return (1);
}
