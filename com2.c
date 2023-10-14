/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:57:26 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:31:17 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	t_node	*tmp;
	char	c;

	tmp = pop_front(a);
	push_back(a, tmp);
	c = a->name;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = pop_front(a);
	push_back(a, tmp);
	tmp = pop_front(b);
	push_back(b, tmp);
	write(1, "rr\n", 3);
}

void	reverse(t_stack *a)
{
	t_node	*tmp;
	char	c;

	tmp = pop_back(a);
	push_front(a, tmp);
	c = a->name;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_all(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = pop_back(a);
	push_front(a, tmp);
	tmp = pop_back(b);
	push_front(b, tmp);
	write(1, "rrr\n", 4);
}
