/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 04:24:42 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a)
	{
		print_error();
		return (1);
	}
	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		print_error();
		return (1);
	}
	if (!is_sorted(stack_a))
		sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
