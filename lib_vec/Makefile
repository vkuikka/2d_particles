NAME = lib_vec.a
SRC = vectors.c
OBJECTS = $(SRC:.c=.o)
INCLUDES = ./
.PHONY: clean fclean re all

all:
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
