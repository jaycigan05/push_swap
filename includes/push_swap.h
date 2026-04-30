/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:39:38 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 10:45:19 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* parse */
t_stack	*parse_args(int argc, char **argv);

/* stack ops - printing wrappers */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* stack ops - silent primitives (used by checker bonus) */
void	do_swap_a(t_stack *a);
void	do_swap_b(t_stack *b);
void	do_rotate_a(t_stack *a);
void	do_rotate_b(t_stack *b);
void	do_rrotate_a(t_stack *a);
void	do_rrotate_b(t_stack *b);

/* sort */
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_stacks(t_stack *a, t_stack *b);
void	assign_index(t_stack *a);
int		get_max_bits(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b, int target);

/* utils */
t_stack	*init_stack(void);
void	print_error(void);
void	free_stack(t_stack *stack);
t_node	*create_node(int value);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
t_node	*peek_top(t_stack *stack);
t_node	*peek_second(t_stack *stack);
int		is_sorted(t_stack *a);

/* checker bonus utils */
char	*ft_strncpy(char *dest, char *src, int n);
char	*read_line(void);

#endif