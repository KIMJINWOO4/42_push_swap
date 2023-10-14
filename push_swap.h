/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:23:23 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/09 17:58:31 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					num;
	int					idx;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_node;

typedef struct s_stack
{
	int						cnt;
	char					name;
	struct s_stack_node		*node[2];
}	t_stack;

enum e_rear
{
	FRONT = 0,
	REAR = 1
};

long long	ft_atoi(const char *str);
void		push_front(t_stack *a, t_node *tmp);
char		**ft_split(char const *str, char c);
int			validate_input(char **input);
void		free_input(char **input);
char		**alloc_input(int argc, char **argv);
char		**input_fill(char **argv, int cnt, int argc);
char		*ft_strdup(const char *s);
int			is_digit(char *str);
int			error_print(int check);
int			is_dup(char **str, int i);
void		init_stack(t_stack *a, t_stack *b, char **input);
int			checker_sort(t_stack *stack);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
void		init_idx_to(t_stack *stack);
void		insert_tail(t_stack *stack, int num);
void		push_back(t_stack *q, t_node *x);
t_node		*pop_front(t_stack *a);
t_node		*pop_back(t_stack *a);
void		swap_all(t_stack *a, t_stack *b);
void		swap(t_stack *a);
void		push(t_stack *a, t_stack *b);
void		three_change(t_stack *a, int *comp);
void		less_el(t_stack *a);
void		reverse_all(t_stack *q, t_stack *p);
void		reverse(t_stack *q);
void		rotate_all(t_stack *q, t_stack *p);
int			compc(int a, int b, int c, int d);
void		rotate(t_stack *q);
void		less_el(t_stack *a);
void		toss_b(t_stack *a, t_stack *b, int piva, int pivb);
int			target_null(t_stack *a, int idx);
int			less_a(t_stack *a, int idx);
int			target_null(t_stack *a, int idx);
void		last_sort(t_stack *a);
void		rotate_alls(t_stack *a, t_stack *b, int *rota, int *rotb);
void		rotate_ab(t_stack *a, t_stack *b, int *rota, int *rotb);
void		find_less(t_stack *a, t_stack *b, int *rota, int *rotb);
void		free_all(t_stack *a, t_stack *b, char **input_str);
#endif