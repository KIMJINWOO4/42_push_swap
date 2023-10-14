/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:32:13 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:58:41 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_stack *a, t_stack *b)
{
	int	rotate_a;
	int	rotate_b;

	if (a->cnt <= 3)
		less_el(a);
	else
	{
		toss_b(a, b, a->cnt / 3, a->cnt / 3 * 2);
		less_el(a);
		while (b->cnt)
		{
			rotate_a = 0;
			rotate_b = 0;
			find_less(a, b, &rotate_a, &rotate_b);
			rotate_alls(a, b, &rotate_a, &rotate_b);
			rotate_ab(a, b, &rotate_a, &rotate_b);
			push(a, b);
		}
		last_sort(a);
	}
}

int	main(int argc, char **argv)
{
	char	**input_str;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			error_print(1);
		input_str = ft_split(argv[1], ' ');
	}
	else
		input_str = alloc_input(argc, argv);
	if (!validate_input(input_str))
		exit(1);
	a = malloc(sizeof(t_stack *) + sizeof(t_node *) * 2);
	b = malloc(sizeof(t_stack *) + sizeof(t_node *) * 2);
	if (!a || !b)
		exit(1);
	init_stack(a, b, input_str);
	greedy(a, b);
	free_all(a, b, input_str);
	exit(0);
}
