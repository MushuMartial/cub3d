NAME = cub3D
SRC = main.c datadivider.c draw.c error.c get_next_line_utils.c get_next_line.c makers.c \
	matrix.c move.c parser.c raycast.c utils.c yasmain.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 
LINKS = -lmlx -framework OpenGL -framework AppKit 
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re