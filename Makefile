.PHONY : all clean fclean re

#files
SRC_FILES = \
	data_structures/chained_lists/ft_lstsize.c \
	data_structures/chained_lists/ft_lstnew.c \
	data_structures/chained_lists/ft_lstmap.c \
	data_structures/chained_lists/ft_lstlast.c \
	data_structures/chained_lists/ft_lstiter.c \
	data_structures/chained_lists/ft_lstdelone.c \
	data_structures/chained_lists/ft_lstclear.c \
	data_structures/chained_lists/ft_lstadd_front.c \
	data_structures/chained_lists/ft_lstadd_back.c \
	data_structures/chained_lists/ft_lst_remove_if.c \
	checks/ft_isalpha.c \
	checks/ft_isdigit.c \
	checks/ft_isalnum.c \
	checks/ft_isascii.c \
	checks/ft_isprint.c \
	checks/ft_toupper.c \
	checks/ft_tolower.c \
	memory/ft_memset.c \
	memory/ft_bzero.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_calloc.c \
	memory/ft_realloc.c \
	strings/ft_strlen.c \
	strings/ft_strlcpy.c \
	strings/ft_strlcat.c \
	strings/ft_strcpy.c \
	strings/ft_strcat.c \
	strings/ft_strchr.c \
	strings/ft_strrchr.c \
	strings/ft_strncmp.c \
	strings/ft_strcmp.c \
	strings/ft_strnstr.c \
	strings/ft_strdup.c \
	strings/ft_substr.c \
	strings/ft_strjoin.c \
	strings/ft_strtrim.c \
	strings/ft_split.c \
	strings/ft_strmapi.c \
	strings/ft_striteri.c \
	conversions/ft_atoi.c \
	conversions/ft_itoa.c \
	files_managing/ft_putchar_fd.c \
	files_managing/ft_putstr_fd.c \
	files_managing/ft_putendl_fd.c \
	files_managing/ft_putnbr_fd.c \
	files_managing/get_next_line.c \
	files_managing/printf/ft_conversions_fd.c \
	files_managing/printf/ft_conversions.c \
	files_managing/printf/printf.c \
	files_managing/printf/printf_fd.c

#directories
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

#files full paths
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.d))

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make --no-print-directory -j

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

-include $(DEP)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
