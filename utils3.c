/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:28 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 16:49:52 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_alls(t_stack *a, t_stack *b, int *rota, int *rotb)
{
	while (*(rota) > 0 && *(rotb) > 0)
	{
		rotate_all(a, b);
		(*rota)--;
		(*rotb)--;
	}
	while (*(rota) < 0 && *(rotb) < 0)
	{
		reverse_all(a, b);
		(*rota)++;
		(*rotb)++;
	}
}

void	rotate_ab(t_stack *a, t_stack *b, int *rota, int *rotb)
{
	while (*rota > 0)
	{
		rotate(a);
		(*rota)--;
	}
	while (*rota < 0)
	{
		reverse(a);
		(*rota)++;
	}
	while (*rotb > 0)
	{
		rotate(b);
		(*rotb)--;
	}
	while (*rotb < 0)
	{
		reverse(b);
		(*rotb)++;
	}
}

void	last_sort(t_stack *a)
{
	int		i;
	t_node	*start;

	i = 0;
	start = a->node[0];
	while (start->idx != 0)
	{
		i++;
		start = start->next;
	}
	if (i > a->cnt / 2)
	{
		while (a->node[0]->idx != 0)
			reverse(a);
	}
	else
	{
		while (a->node[0]->idx != 0)
			rotate(a);
	}
}

void	find_less(t_stack *a, t_stack *b, int *rota, int *rotb)
{
	int		find_a;
	int		find_b;
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = b->node[0];
	while (tmp)
	{
		find_a = less_a(a, tmp->idx);
		if (i > b->cnt / 2)
			find_b = i - b->cnt;
		else
			find_b = i;
		if (i == 0 || compc(*(rota), *(rotb), find_a, find_b))
		{
			*(rota) = find_a;
			*(rotb) = find_b;
		}
		tmp = tmp->next;
		i++;
	}
}

int	compc(int a, int b, int c, int d)
{
	int	now;
	int	next;

	now = 0;
	next = 0;
	if (a < 0)
		now += a * -1;
	else
		now = a;
	if (b < 0)
		now += b * -1;
	else
		now += b;
	if (c < 0)
		next += c * -1;
	else
		next = c;
	if (d < 0)
		next += d * -1;
	else
		next += d;
	if (now > next)
		return (1);
	return (0);
}
