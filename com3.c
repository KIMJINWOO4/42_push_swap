/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:49:09 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:31:45 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *a, t_node *tmp)
{
	a->cnt++;
	tmp->prev = NULL;
	if (a->node[0] == NULL)
	{
		a->node[0] = tmp;
		a->node[1] = tmp;
		tmp->next = NULL;
		return ;
	}
	a->node[0]->prev = tmp;
	tmp->next = a->node[0];
	a->node[0] = tmp;
}

void	push_back(t_stack *a, t_node *tmp)
{
	a->cnt++;
	tmp->next = NULL;
	if (a->node[1] == NULL)
	{
		a->node[0] = tmp;
		a->node[1] = tmp;
		tmp->prev = NULL;
		return ;
	}
	a->node[1]->next = tmp;
	tmp->prev = a->node[1];
	a->node[1] = tmp;
}

t_node	*pop_front(t_stack *a)
{
	t_node	*tmp;

	if (a->node[0] == NULL)
		return (NULL);
	tmp = a->node[0];
	a->cnt--;
	if (a->node[0]->next == NULL)
	{
		a->node[0] = NULL;
		a->node[1] = NULL;
		return (tmp);
	}
	a->node[0] = a->node[0]->next;
	tmp->next = NULL;
	a->node[0]->prev = NULL;
	return (tmp);
}

t_node	*pop_back(t_stack *a)
{
	t_node	*tmp;

	if (a->node[1] == NULL)
		return (NULL);
	tmp = a->node[1];
	a->cnt--;
	if (a->node[1]->prev == NULL)
	{
		a->node[0] = NULL;
		a->node[1] = NULL;
		return (tmp);
	}
	a->node[1] = a->node[1]->prev;
	tmp->prev = NULL;
	a->node[1]->next = NULL;
	return (tmp);
}
