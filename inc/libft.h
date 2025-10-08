/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:53:27 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:45:54 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// CHECKS

int							ft_isalnum(int c);
int							ft_isalpha(int c);
int							ft_isascii(int c);
int							ft_isdigit(int c);
int							ft_isprint(int c);
int							ft_tolower(int c);
int							ft_toupper(int c);

// CONVERSIONS

int							ft_atoi(const char *nptr);
char						*ft_itoa(int n);

// DATA_STRUCTURES

// CHAINED_LIST

typedef struct s_lst_node	t_lst_node;
typedef struct s_list		t_list;
t_list						*lst_new(void *content);
t_lst_node					*lst_node_new(void *content);
t_lst_node					*lst_first(t_list *lst);
t_lst_node					*lst_last(t_list *lst);
void						lst_add_front(t_list *lst, t_lst_node *new);
void						lst_add_back(t_list *lst, t_lst_node *new);
void						lst_delone(t_lst_node *node, void (*del)(void *));
void						lst_remove_first(t_list *lst, void (*del)(void *));
void						lst_remove_after(t_list *lst, t_lst_node *node,
								void (*del)(void *));
void						lst_remove_if(t_list *lst, void *data_ref,
								bool (*cmp)(void *, void *),
								void (*del)(void *));
void						lst_clear(t_list *lst, void (*del)(void *));
void						lst_iter(t_list *lst, void (*f)(void *));
t_list						*lst_map(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
void						*lst_node_get(t_lst_node *node);
void						lst_node_set(t_lst_node *node, void *content);
t_lst_node					*lst_node_next(t_lst_node *node);
t_lst_node					*lst_node_at(t_list *lst, size_t index);

// VECTOR

typedef struct s_vector		t_vector;
t_vector					*vector_create(size_t capacity,
								size_t element_size);
size_t						vector_size(t_vector *vect);
bool						vector_resize(t_vector *vect, size_t new_size);
void						*vector_get(t_vector *vect, size_t index);
void						vector_set(t_vector *vect, size_t index,
								void *element);
bool						vector_push(t_vector *vect, void *element);
void						vector_delete(t_vector *vect, void (*del)(void *));

// STACK

typedef struct s_stack		t_stack;
t_stack						*stack_create(size_t capacity, size_t element_size);
bool						stack_is_empty(t_stack *stk);
bool						stack_push(t_stack *stk, void *element);
void						*stack_top(t_stack *stk);
void						*stack_pop(t_stack *stk);
void						stack_delete(t_stack *stk, void (*del)(void *));

// QUEUE

typedef struct s_queue		t_queue;
t_queue						*queue_create(size_t capacity, size_t element_size);
size_t						queue_size(t_queue *q);
bool						queue_is_empty(t_queue *q);
bool						queue_enqueue(t_queue *q, void *element);
void						*queue_peek(t_queue *q);
void						*queue_dequeue(t_queue *q);
void						queue_delete(t_queue *q, void (*del)(void *));

// key_cmp must return:
// a negative value if first_key is less than second_key
// a positive value if first_key is greater than second_key
// 0 if both keys are equal.
// Only the sign of the return (value is considered);
// the exact magnitude does not matter.

// HASH TABLE

typedef struct s_hashtbl	t_hashtbl;
# define INITIAL_BUCKET_COUNT 16
# define HASHTBL_LOAD_FACTOR_LIMIT 0.75f

typedef enum e_hashtbl_status
{
	HASHTBL_OK,
	HASHTBL_ERR_INVALID,
	HASHTBL_ERR_ALLOC
}							t_hashtbl_status;

t_hashtbl					*hashtbl_create(size_t capacity,
								int (*key_cmp)(void *first_key,
									void *second_key));
t_hashtbl_status			hashtbl_put(t_hashtbl *h, void *key, void *value);
bool						hashtbl_contains(t_hashtbl *h, void *key);
void						*hashtbl_get(t_hashtbl *h, void *key);
void						hashtbl_remove(t_hashtbl *h, void *key);
void						hashtbl_delete(t_hashtbl *h);

// BINARY TREE

typedef struct s_bin_tree	t_bin_tree;

t_bin_tree					*bin_tree_create(t_bin_tree *left, void *content,
								t_bin_tree *right);
void						bin_tree_delete(t_bin_tree *tree,
								void (*del)(void *));
t_bin_tree					*bin_tree_perfect_create(size_t height,
								void (*del)(void *));
size_t						bin_tree_size(t_bin_tree *tree);
void						bin_tree_traverse_preorder(t_bin_tree *tree,
								void (*f)(void *));
void						bin_tree_traverse_inorder(t_bin_tree *tree,
								void (*f)(void *));
void						bin_tree_traverse_postorder(t_bin_tree *tree,
								void (*f)(void *));

// BINARY SEARCH TREE

typedef struct s_bst		t_bst;
t_bst						*bst_create(void *key, void *value,
								int (*key_cmp)(void *first_key,
									void *second_key));
size_t						bst_size(t_bst *tree);
void						*bst_min(t_bst *tree);
void						*bst_search(t_bst *tree, void *key);
bool						bst_insert(t_bst *tree, void *key, void *value);
bool						bst_remove(t_bst *tree, void *key,
								void (*del)(void *));
bool						bst_delete(t_bst *tree, void (*del)(void *));

// HEAP

typedef struct s_heap		t_heap;
t_heap						*heap_create(size_t capacity,
								int (*key_cmp)(void *first_key,
									void *second_key));
bool						heap_insert(t_heap *heap, void *key, void *value);
void						*heap_extract_priority(t_heap *heap);
void						*heap_peek(t_heap *heap);
void						heap_delete(t_heap *heap, void (*del)(void *));

// FILES_MANAGING

ssize_t						ft_putchar_fd(char c, int fd);
ssize_t						ft_putstr_fd(char *s, int fd);
ssize_t						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);
int							ft_printf(const char *format, ...);
int							ft_printf_fd(int fd, const char *format, ...);
char						*get_next_line(int fd);

// MEMORY

int							ft_memcmp(const void *s1, const void *s2, size_t n);
void						ft_bzero(void *dest, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memset(void *dest, int value, size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
void						*ft_calloc(size_t nmemb, size_t size);
void						*ft_realloc(void *ptr, size_t old_size,
								size_t new_size);

// STRINGS

char						*ft_strcat(char *dst, const char *src);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strnstr(const char *big, const char *little,
								size_t len);
char						*ft_strdup(const char *s);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s1, char const *set);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
char						**ft_split(char const *s, char c);
size_t						ft_strlen(const char *s);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
size_t						ft_strlcpy(char *dst, const char *src, size_t size);

#endif
