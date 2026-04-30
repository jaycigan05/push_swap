/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:57:19 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:00:46 by jagan            ###   ########.fr       */
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

int	execute_operation(t_stack *a, t_stack *b, char *op)
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
