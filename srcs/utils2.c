/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*peek_top(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top);
}

t_node	*peek_second(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (NULL);
	return (stack->top->next);
}

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
