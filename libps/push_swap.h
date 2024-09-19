/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:32:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/19 14:22:25 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_newnode(int *content);
t_stack				*ft_lastnode(t_stack *stack);
void				ft_addnode_back(t_stack **stack, t_stack *new_node);

void				ft_push_a(t_stack **stack_a, t_stack **stack_b);
void				ft_push_b(t_stack **stack_a, t_stack **stack_b);

void				ft_swap_ss(t_stack **stack_a, t_stack **stack_b);
void				ft_swap_b(t_stack **stack_b);
void				ft_swap_a(t_stack **stack_a);

void				ft_reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b);
void				ft_reverse_rotate_b(t_stack **stack_b);
void				ft_reverse_rotate_a(t_stack **stack_a);

void				ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rotate_b(t_stack **stack_b);
void				ft_rotate_a(t_stack **stack_a);

void				ft_perror(char *msg);

void				ft_free_split(char **args);
void	            ft_free_stacks(t_stack **stack_a, t_stack **stack_b);
void	            ft_free_stack(t_stack *stack);

int					ft_count_args(char **args);
int					ft_check_args(int argc, char **args, int i);
int					ft_isinvalid_char(char *str);
int					ft_check_nbr(const char *str);
int					ft_check_duplicate(int argc, char **argv, int i);

t_bool				ft_tab_is_sorted(int *tab, int size, int i);
int                 ft_tabsize(int *tab);

t_bool				ft_stack_is_sorted(t_stack **stack);
int					ft_stacksize(t_stack *stack);
int					ft_find_min(t_stack **stack);
void                ft_printf_stack_content(t_stack *stack);

void				ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void				ft_sort_2(t_stack **stack_a);
void				ft_sort_3(t_stack **stack_a);
void				ft_sort_4(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_5(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_stack(t_stack **stack_a, int size);

#endif