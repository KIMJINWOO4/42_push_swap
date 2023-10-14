/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:24:38 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:55:54 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**alloc_input(int argc, char **argv)
{
	char			**input;
	int				cnt;
	int				i;
	int				j;

	i = 0;
	cnt = 0;
	while (++i < argc)
	{
		j = -1;
		input = ft_split(argv[i], ' ');
		if (!input)
			exit(1);
		while (input[++j])
			cnt++;
		free_input(input);
	}
	input = input_fill(argv, cnt, argc);
	if (!input)
		exit(1);
	return (input);
}

char	**input_fill(char **argv, int cnt, int argc)
{
	char	**input;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	input = (char **)malloc(sizeof(char *) * cnt + 1);
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
			input[k++] = tmp[j++];
		free(tmp);
		i++;
	}
	input[cnt] = NULL;
	return (input);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (*(s + i))
		i++;
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(tmp + i) = *(s + i);
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

int	validate_input(char **input)
{
	int			i;

	i = -1;
	if (!input)
		return (0);
	while (input[++i])
	{
		if (!is_digit(input[i]))
			return (error_print(1));
		if (!is_dup(input, i))
			return (error_print(1));
	}
	return (1);
}

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
