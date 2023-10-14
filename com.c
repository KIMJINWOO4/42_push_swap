/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:04:30 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:30:45 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	char	c;

	if (b->cnt == 0)
		return ;
	tmp = pop_front(b);
	push_front(a, tmp);
	c = a->name;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap(t_stack *a)
{
	t_node	*tmp1;
	t_node	*tmp2;
	char	c;

	tmp1 = pop_front(a);
	tmp2 = pop_front(a);
	push_front(a, tmp1);
	push_front(a, tmp2);
	c = a->name;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_all(t_stack *a, t_stack *b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_front(a);
	tmp2 = pop_front(b);
	push_front(a, tmp1);
	push_front(b, tmp2);
	tmp1 = pop_front(a);
	tmp2 = pop_front(b);
	push_front(a, tmp1);
	push_front(b, tmp2);
	write(1, "ss\n", 3);
}
