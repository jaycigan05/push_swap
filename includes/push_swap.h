/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:39:38 by jagan             #+#    #+#             */
/*   Updated: 2026/03/22 15:07:46 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

// Data Structure
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

// Parsing and Validation
t_stack	*parse_args(int argc, char **argv);
int		is_valid_integer(char *str);
int		has_duplicates(t_stack *stack);

// Stack Operations (Mandatory)
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

// Sorting
void	sort_stacks(t_stack *a, t_stack *b);

// Utilities
void	print_error(void);
void	free_stack(t_stack *stack);
t_node	*create_node(int value);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
int		is_sorted(t_stack *a);

#endif