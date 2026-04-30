/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:39:38 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:45:44 by jagan            ###   ########.fr       */
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

typedef struct s_move
{
	int	index;
	int	position;
	int	cost_a;
	int	cost_b;
}	t_move;

typedef struct s_lis
{
	t_node	**nodes;
	int		*dp;
	int		*prev;
	int		size;
	int		best_end;
}	t_lis;

t_node	**build_lis_set(t_stack *a, int *lis_size);
void	apply_rotations_and_push(t_stack *a, t_stack *b,
			int cost_a, int cost_b);
void	rotate_a_to_min(t_stack *a);

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
void	sort_large(t_stack *a, t_stack *b);
void	move_best_node(t_stack *a, t_stack *b);
void	rotate_a_to_min(t_stack *a);
void	assign_index(t_stack *a);
int		get_max_bits(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b, int target);
int		is_node_in_set(t_node *node, t_node **set, int set_size);
t_node	**build_lis_set(t_stack *a, int *lis_size);
int		get_insert_position(t_stack *a, int index);
int		get_rotation_cost(int position, int size);
int		get_total_cost(int cost_a, int cost_b);

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

/*checker exec.*/
int		execute_operation(t_stack *a, t_stack *b, char *op);

t_node	**copy_stack_nodes(t_stack *a);
void	init_lis_arrays(t_lis *lis);
void	compute_lis(t_lis *lis);
t_node	**extract_lis(t_lis *lis, int *size);

#endif