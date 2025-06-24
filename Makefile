.PHONY : all clean fclean re

#files
SRC_FILES = \
	data_structures/chained_list/lst_add_back.c \
	data_structures/chained_list/lst_add_front.c \
	data_structures/chained_list/lst_clear.c \
	data_structures/chained_list/lst_delone.c \
	data_structures/chained_list/lst_first.c \
	data_structures/chained_list/lst_iter.c \
	data_structures/chained_list/lst_last.c \
	data_structures/chained_list/lst_map.c \
	data_structures/chained_list/lst_new.c \
	data_structures/chained_list/lst_remove_after.c \
	data_structures/chained_list/lst_remove_first.c \
	data_structures/chained_list/lst_remove_if.c \
	data_structures/chained_list/node_at.c \
	data_structures/chained_list/node_get.c \
	data_structures/chained_list/node_new.c \
	data_structures/chained_list/node_next.c \
	data_structures/chained_list/node_set.c \
	data_structures/hash_table/hash_function.c \
	data_structures/hash_table/hash_utils.c \
	data_structures/hash_table/hashtbl_bucket_prepend.c \
	data_structures/hash_table/hashtbl_contains.c \
	data_structures/hash_table/hashtbl_create.c \
	data_structures/hash_table/hashtbl_delete.c \
	data_structures/hash_table/hashtbl_put.c \
	data_structures/hash_table/hashtbl_get.c \
	data_structures/hash_table/hashtbl_remove.c \
	data_structures/hash_table/hashtbl_resize.c \
	data_structures/queue/queue_create.c \
	data_structures/queue/queue_delete.c \
	data_structures/queue/queue_dequeue.c \
	data_structures/queue/queue_enqueue.c \
	data_structures/queue/queue_is_empty.c \
	data_structures/queue/queue_peek.c \
	data_structures/queue/queue_size.c \
	data_structures/stack/stack_create.c \
	data_structures/stack/stack_delete.c \
	data_structures/stack/stack_is_empty.c \
	data_structures/stack/stack_pop.c \
	data_structures/stack/stack_push.c \
	data_structures/stack/stack_top.c \
	data_structures/vector/vector_create.c \
	data_structures/vector/vector_delete.c \
	data_structures/vector/vector_get.c \
	data_structures/vector/vector_push.c \
	data_structures/vector/vector_resize.c \
	data_structures/vector/vector_set.c \
	data_structures/vector/vector_size.c \
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

NAME = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

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
