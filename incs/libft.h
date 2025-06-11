/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:53:27 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/11 13:47:32 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//CHECKS

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

//CONVERSIONS

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

//DATA_STRUCTURES

//  CHAINED_LIST

typedef struct s_list t_list;
t_list		*ft_lstnew(void *content);
size_t		ft_lstsize(t_list *lst);
void		*ft_lstget(t_list *node);
void		ft_lstset(t_list *node, void *content);
t_list		*ft_lstnext(t_list *node);
t_list		*ft_lst_at(t_list *lst, size_t index);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *node, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lst_remove_if(t_list **lst, void *data_ref, bool (*cmp)(void*, void*), void (*del)(void*));

//  VECTOR

typedef struct s_vector vector;
vector		*vector_create(size_t capacity, size_t element_size);
size_t		vector_size(vector *vect);
void		*vector_get(vector *vect, size_t index);
void		vector_set(vector *vect, size_t index, void *element);
bool		vector_resize(vector *vect, size_t new_size);
bool		vector_push(vector *vect, void *element);
void		vector_delete(vector *vect);

//  STACK

typedef struct s_stack stack;
stack		*stack_create(size_t capacity, size_t element_size);
bool		stack_is_empty(stack *stk);
bool		stack_push(stack *stk, void *element);
void		*stack_pop(stack *stk);
void		*stack_top(stack *stk);
void		stack_delete(stack *stk);

//  QUEUE



//FILES_MANAGING

ssize_t			ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr_fd(char *s, int fd);
ssize_t		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
char		*get_next_line(int fd);

//MEMORY

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *dest, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *dest, int value, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void 		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//STRINGS

char		*ft_strcat(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

#endif
