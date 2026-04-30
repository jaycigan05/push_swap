/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_swap_ops(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a' && op[2] == '\0')
		do_swap_a(a);
	else if (op[1] == 'b' && op[2] == '\0')
		do_swap_b(b);
	else if (op[1] == 's' && op[2] == '\0')
	{
		do_swap_a(a);
		do_swap_b(b);
	}
	else
		return (0);
	return (1);
}

static int	exec_rot_ops(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a' && op[2] == '\0')
		do_rotate_a(a);
	else if (op[1] == 'b' && op[2] == '\0')
		do_rotate_b(b);
	else if (op[1] == 'r' && op[2] == '\0')
	{
		do_rotate_a(a);
		do_rotate_b(b);
	}
	else if (op[1] == 'r' && op[2] == 'a' && op[3] == '\0')
		do_rrotate_a(a);
	else if (op[1] == 'r' && op[2] == 'b' && op[3] == '\0')
		do_rrotate_b(b);
	else if (op[1] == 'r' && op[2] == 'r' && op[3] == '\0')
	{
		do_rrotate_a(a);
		do_rrotate_b(b);
	}
	else
		return (0);
	return (1);
}

static int	execute_operation(t_stack *a, t_stack *b, char *op)
{
	t_node	*node;

	if (!op || op[0] == '\0')
		return (1);
	if (op[0] == 's')
		return (exec_swap_ops(a, b, op));
	else if (op[0] == 'p' && op[1] == 'a' && op[2] == '\0')
	{
		node = pop_node(b);
		if (node)
			push_node(a, node);
	}
	else if (op[0] == 'p' && op[1] == 'b' && op[2] == '\0')
	{
		node = pop_node(a);
		if (node)
			push_node(b, node);
	}
	else if (op[0] == 'r')
		return (exec_rot_ops(a, b, op));
	else
		return (0);
	return (1);
}

static int	run_checker(t_stack *a, t_stack *b)
{
	char	*op;

	while (1)
	{
		op = read_line();
		if (!op)
			break ;
		if (op[0] != '\0' && !execute_operation(a, b, op))
		{
			free(op);
			free_stack(a);
			free_stack(b);
			print_error();
			return (1);
		}
		free(op);
	}
	return (0);
}

static int	init_checker(t_stack **stack_a, t_stack **stack_b, int argc,
	char **argv)
{
	*stack_a = parse_args(argc, argv);
	if (!*stack_a)
	{
		print_error();
		return (0);
	}
	*stack_b = init_stack();
	if (!*stack_b)
	{
		free_stack(*stack_a);
		print_error();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!init_checker(&stack_a, &stack_b, argc, argv))
		return (1);
	if (run_checker(stack_a, stack_b))
		return (1);
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
