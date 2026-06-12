NAME = music.exe
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c music_list.c music_engine.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@if exist main.o del /q main.o music_list.o music_engine.o

fclean: clean
	@if exist $(NAME) del /q $(NAME)

re: fclean all

run: all
	./$(NAME) albums.txt artist

.PHONY: all clean fclean re run