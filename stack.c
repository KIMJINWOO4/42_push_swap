/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:47:09 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:55:46 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		insert_tail(stack, (int)ft_atoi(input[i]));
}

void	init_stack(t_stack *a, t_stack *b, char **input)
{
	if (!a || !b)
		exit(1);
	a->node[0] = NULL;
	a->node[1] = NULL;
	a->cnt = 0;
	a->name = 'a';
	b->name = 'b';
	b->node[0] = NULL;
	b->node[1] = NULL;
	b->cnt = 0;
	fill_stack(a, input);
	if (checker_sort(a))
		error_print(0);
	init_idx_to(a);
	return ;
}

t_node	*init_node(int num)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		exit(1);
	tmp->num = num;
	tmp->idx = 0;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	insert_tail(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = init_node(num);
	if (!stack->node[0])
	{
		stack->node[0] = new_node;
		stack->node[1] = new_node;
	}
	else
	{
		new_node->prev = stack->node[1];
		stack->node[1]->next = new_node;
		stack->node[1] = new_node;
	}
	stack->cnt++;
	return ;
}
