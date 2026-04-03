/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:46:18 by jagan             #+#    #+#             */
/*   Updated: 2026/04/04 05:18:11 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa: Swap the first 2 elements at the top of stack a
void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int	temp;

	first = peek_top(a);
	second = peek_second(a);
	if (!first || !second)
		return ;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	printf("sa\n");
}

//sb: Swap the first 2 elements at the top of stack b
void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int	temp;

	first = peek_top(b);
	second = peek_second(b);
	if (!first || !second)
		return ;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	print("sb\n");
}

// ss: sa and sb at the same time
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

//pa: Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop_node(b);
	if (!node)
		return ;
	push_node(a, node);
	printf("pa\n");
}

//pb: Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;
	
	node = pop_node(a);
	if (!node)
		return ;
	push_node(b, node);
	printf("pb\n");
}