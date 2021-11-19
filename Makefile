NAME = sim
SRC = main.c init.c input.c physics.c particle_physics/water.c particle_physics/sand.c particle_physics/lava.c
LIB = libft/libft.a lib_vec/lib_vec.a
FLAGS = -Wall -Wextra -Werror
SDL = `sdl2-config --cflags` `sdl2-config --libs`

all:
	gcc -O3 -fsanitize=address -g -o $(NAME) $(SRC) $(LIB) $(SDL)
