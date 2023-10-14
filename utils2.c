/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:30:19 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:55:59 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *str)
{
	int			i;

	i = 1;
	if (str[0] == '-' || ft_isdigit(str[0]))
	{
		if ((str[0] == '-' && str[1] == '0')
			|| (str[0] == '-' && str[1] == '\0'))
			error_print(1);
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	ft_atoi(str);
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_dup(char **str, int i)
{
	int	j;

	j = i + 1;
	while (str[j])
	{
		if (ft_atoi(str[i]) == ft_atoi(str[j]))
			return (0);
		j++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)*(s1 + i) == (unsigned char)*(s2 + i))
			i++;
		else
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	}
	return (0);
}

int	error_print(int check)
{
	if (check == 1)
		write(2, "Error\n", 6);
	else if (check == 2)
		exit(1);
	exit(1);
	return (-1);
}
