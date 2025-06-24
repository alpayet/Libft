/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:06:58 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 04:23:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES
# define STRUCTURES
# include "libft.h"

typedef struct s_node
{
	void	*content;
	t_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}	t_list;

typedef struct s_vector
{
	size_t capacity;
	size_t size; //number of elements occupied in the array, 0 <= size <= capacity
	void *data; //array of "capacity" elements
	size_t element_size;  //size of an array element
}	vector;

typedef struct s_stack
{
	vector *vect;
}	stack;

typedef struct s_queue
{
	size_t capacity;
	size_t size;
	size_t front;
	void *data;
	size_t element_size;
} queue;

typedef struct s_entry
{
	char *key;
	void *value;
} entry;

typedef struct s_hashtbl
{
	vector *vect;
	size_t count; //total number of inserted elements
}	t_hashtbl;

#endif
