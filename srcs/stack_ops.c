/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:46:18 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap_a(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	first = peek_top(a);
	second = peek_second(a);
	if (!first || !second)
		return ;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	do_swap_b(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	first = peek_top(b);
	second = peek_second(b);
	if (!first || !second)
		return ;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_stack *a)
{
	do_swap_a(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	do_swap_b(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	do_swap_a(a);
	do_swap_b(b);
	write(1, "ss\n", 3);
}
