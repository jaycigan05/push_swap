/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:56:28 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:00:13 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	init_checker(t_stack **stack_a, t_stack **stack_b,
	int argc, char **argv)
{
	*stack_a = parse_args(argc, argv);
	if (!*stack_a)
		return (print_error(), 0);
	*stack_b = init_stack();
	if (!*stack_b)
	{
		free_stack(*stack_a);
		return (print_error(), 0);
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
