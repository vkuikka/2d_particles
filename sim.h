#ifndef SIM_H
# define SIM_H

# define SIM_SIZE 300
# define RES_SCALE 2
# define RES_X (int)(SIM_SIZE * RES_SCALE)
# define RES_Y (int)(SIM_SIZE * RES_SCALE)

// # define THREAD_AMOUNT 4

# include <math.h>
# include <SDL2/SDL.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# include "lib_vec/lib_vec.h"

# define COLOR_WATER 0x168bd9
# define COLOR_SAND 0xd6a33c
# define COLOR_STONE 0x777777
# define COLOR_LAVA 0x992222
# define COLOR_VOID 0x211342

typedef enum s_particle
{
	EMPTY = 0,
	DISAPPEARING,
	APPEARING_WATER,
	APPEARING_LAVA,
	WATER,
	SAND,
	STONE,
	LAVA,
	VOID,
}			e_particle;

typedef struct s_world
{
	e_particle			sim[SIM_SIZE][SIM_SIZE];
	e_particle			addition;
	int					shift_down;
	int					pause;
}						t_world;

typedef struct s_window
{
	SDL_Renderer		*SDLrenderer;
	SDL_Window			*SDLwindow;
	SDL_Texture			*texture;
	unsigned int		*frame_buffer;
}						t_window;

void	init_window(t_window **window);
void	init_world(t_world **world);

void	input(t_world *world);

void	physics(t_world *world);

int		move_side_lava(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v);
int		move_side_sand(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v);
int		move_side_water(e_particle s[SIM_SIZE][SIM_SIZE], t_ivec2 v);

#endif
