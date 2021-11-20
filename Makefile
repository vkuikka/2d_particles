NAME = sim
SRC = main.c\
	init.c\
	input.c\
	physics.c\
	particle_physics/water.c\
	particle_physics/sand.c\
	particle_physics/lava.c
FILES = $(addprefix src/, $(SRC))
LIB = libft/libft.a lib_vec/lib_vec.a
HEADERS = -I libft/includes -I lib_vec
FLAGS = -Wall -Wextra -Werror
SDL = `sdl2-config --cflags` `sdl2-config --libs`


all:
	@make -C libft
	@make -C lib_vec
	gcc -O3 -fsanitize=address -g -o $(NAME) $(FILES) $(LIB) $(HEADERS) $(SDL)

$(NAME): $(FILES)
	gcc -O3 -fsanitize=address -g -o $(NAME) $(FILES) $(LIB) $(HEADERS) $(SDL)

clean:
	@make clean -C libft
	@make clean -C lib_vec

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C lib_vec

re: fclean
	make all
