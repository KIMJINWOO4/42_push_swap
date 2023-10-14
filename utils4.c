/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:57:51 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:58:45 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = a->node[0];
	while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	free(a);
	return ;
}

void	free_all(t_stack *a, t_stack *b, char **input_str)
{
	int		i;

	i = 0;
	free_stack(a);
	free_stack(b);
	while (input_str[i] != 0)
	{
		free(input_str[i]);
		i++;
	}
	free(input_str);
	return ;
}
