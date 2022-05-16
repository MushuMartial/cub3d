NAME = cub3D

SRC = main.c datadivider.c datadivider2.c draw.c error.c error2.c\
	get_next_line_utils.c get_next_line.c makers.c \
	matrix.c move.c move2.c parser.c parser2.c parser3.c raycast.c \
	utils.c yasmain.c spacegain.c spacegain2.c\

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
