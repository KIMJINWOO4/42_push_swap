/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:20:21 by jinwokim          #+#    #+#             */
/*   Updated: 2023/09/05 14:12:45 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_sort(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->node[0];
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	init_idx_to(t_stack *stack)
{
	t_node	*tmp;
	t_node	*b;
	int		j;
	int		i;

	i = 0;
	while (i < stack->cnt)
	{
		j = -1;
		tmp = stack->node[0];
		b = stack->node[0];
		while (++j < i)
			b = b->next;
		while (tmp)
		{
			if (b->num > tmp->num)
				b->idx++;
			tmp = tmp->next;
		}
		i++;
	}
	return ;
}
