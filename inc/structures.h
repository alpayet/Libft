/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:06:58 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:49:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libft.h"

typedef struct s_lst_node
{
	void				*content;
	t_lst_node			*next;
}						t_lst_node;

typedef struct s_list
{
	t_lst_node			*first;
	t_lst_node			*last;
	size_t				size;
}						t_list;

// 0 <= size <= capacity
// array of "capacity" elements
typedef struct s_vector
{
	size_t				capacity;
	size_t				size;
	void				*data;
	size_t				element_size;
}						t_vector;

typedef struct s_stack
{
	t_vector			*vect;
}						t_stack;

typedef struct s_queue
{
	size_t				capacity;
	size_t				size;
	size_t				front;
	void				*data;
	size_t				element_size;
}						t_queue;

typedef struct s_entry
{
	void				*key;
	void				*value;
}						t_entry;

typedef struct s_hashtbl
{
	t_vector			*vect;
	size_t				count;
	int					(*key_cmp)(void *, void *);
}						t_hashtbl;

typedef struct s_bin_tree
{
	t_bin_tree			*left;
	void				*content;
	t_bin_tree			*right;
}						t_bin_tree;

typedef struct s_bst_node
{
	struct s_bst_node	*left;
	void				*key;
	void				*value;
	struct s_bst_node	*right;
}						t_bst_node;

typedef struct s_bst
{
	t_bst_node			*root;
	int					(*key_cmp)(void *, void *);
}						t_bst;

typedef struct s_heap
{
	t_vector			*vect;
	int					(*key_cmp)(void *, void *);
}						t_heap;

#endif
