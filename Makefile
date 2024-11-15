CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = libft.a
INC = libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : 
