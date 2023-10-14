/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:17:16 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:00:53 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_el(t_stack *a)
{
	int	comp[3];

	if (a->cnt == 2)
		swap(a);
	if (a->cnt == 3)
	{
		comp[0] = a->node[0]->idx;
		comp[1] = a->node[0]->next->idx;
		comp[2] = a->node[1]->idx;
		if (comp[0] > comp[1] && comp[0] > comp[2])
		{
			if (comp[1] < comp[2])
				rotate(a);
			else
			{
				swap(a);
				reverse(a);
			}
		}
		else
			three_change(a, comp);
	}
	return ;
}

void	three_change(t_stack *a, int *comp)
{
	if (comp[0] < comp[1] && comp[0] < comp[2])
	{
		if (comp[1] < comp[2])
			return ;
		swap(a);
		rotate(a);
	}
	else
	{
		if (comp[1] < comp[2])
			swap(a);
		else
			reverse(a);
	}
	return ;
}

void	toss_b(t_stack *a, t_stack *b, int piva, int pivb)
{
	int	i;

	i = a->cnt;
	while (i > 3 && i)
	{
		if (a->node[0]->idx <= piva)
		{
			push(b, a);
			rotate(b);
		}
		else if (a->node[0]->idx <= pivb)
			push(b, a);
		else
			rotate(a);
		i--;
	}
	while (a->cnt > 3)
		push(b, a);
}

int	target_null(t_stack *a, int idx)
{
	t_node	*p;

	p = a->node[0];
	if (p->prev == NULL && a->node[1]->idx > idx
		&& p->idx > idx && a->node[1]->idx > p->idx)
		return (1);
	if (p->prev == NULL && a->node[1]->idx < idx
		&& p->idx > idx && a->node[1]->idx < p->idx)
		return (1);
	if (p->prev == NULL && a->node[1]->idx < idx
		&& p->idx < idx && a->node[1]->idx > p->idx)
		return (1);
	return (0);
}

int	less_a(t_stack *a, int idx)
{
	t_node	*p;
	int		cnt;

	cnt = 0;
	p = a->node[0];
	while (p)
	{
		if (p == a->node[0] && target_null(a, idx))
			break ;
		if (p->prev != NULL && p->prev->idx > idx
			&& p->idx > idx && p->prev->idx > p->idx)
			break ;
		if (p->prev != NULL && p->prev->idx < idx
			&& p->idx > idx && p->prev->idx < p->idx)
			break ;
		if (p->prev != NULL && p->prev->idx < idx
			&& p->idx < idx && p->prev->idx > p->idx)
			break ;
		p = p->next;
		cnt++;
	}
	if (cnt > a->cnt / 2)
		cnt = cnt - a->cnt;
	return (cnt);
}
