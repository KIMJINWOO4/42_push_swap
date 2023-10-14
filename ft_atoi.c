/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:47:51 by jinwokim          #+#    #+#             */
/*   Updated: 2023/09/05 14:08:48 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	space_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			i++;
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

static long long	ft_cal(long long result, int flag)
{
	long long	checkrange;

	if (flag == 1)
		checkrange = result * -1;
	else
		checkrange = result;
	if (checkrange > 2147483647 || checkrange < -2147483648)
		return (error_print(1));
	return (checkrange);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			flag;
	long long	result;

	result = 0;
	flag = 0;
	i = space_check(str);
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			flag++;
		i++;
	}
	while (*(str + i))
	{
		if (*(str + i) >= 48 && *(str + i) <= 57)
		{
			result *= 10;
			result += (*(str + i)) - '0';
		}
		else
			break ;
		i++;
	}
	return (ft_cal(result, flag));
}
