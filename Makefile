NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
      get_next_line_utils.c

OBJ = $(SRC:.c=.o)

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re