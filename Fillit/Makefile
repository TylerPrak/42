NAME = fillit

CC = gcc -Wall -Werror -Wextra

SRC = ./main.c ./read.c ./checks.c ./check_hashes.c ./store.c ./map.c ./solve.c 

OBJ = $(SRC:.c=.o)
	
INCLD = -I libft -L libft -lft

all: $(NAME)

$(NAME) : $(OBJ)
	@make all -C libft
	@$(CC) -c $(SRC)
	$(CC) $(OBJ) -o fillit $(INCLD)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
