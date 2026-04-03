/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:22:20 by jagan             #+#    #+#             */
/*   Updated: 2026/04/02 09:48:12 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//ra : Shift up all elements of stack a by 1. The first element becomes the last one.
void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (!a || a->size < 2)
		return ;
	first = pop_node(a);
	if (!first)
		return ;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	a->top = a->top;
}

//rb: Shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (!b || b->size < 2)
		return ;
	first = pop_node(b);
	if (!first)
		return ;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	b->top = b->top;
}//为什么在最后还要写两次b->top?什么作用？

// rr: ra and rb at the same time
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

//rra: Shift down all elements of stack a by 1. The last element becomes the first one.
void	rra(t_stack *a)
{
	t_node	*current;
	t_node	*second_last;

	if (!a ||a->size < 2)
		return ;
	current = a->top;
	if (!current || !current->next)
		return ;
	while (current->next->next)
		current = current->next;
	second_last = current;
	current = current->next;
	second_last->next = NULL;
	current->next = a->top;
	a->top = current;
}//不明白line75,76,77, explain line 69

//rrb: Shift down all elements of stack b by 1. The last element becomes the  first one.
void	rrb(t_stack *b)
{
	t_node	*current;
	t_node	*second_last;

	if (!b || b->size < 2)
		return ;
	current = b->top;
	if (!current || !current->next)
		return ;
	while (current->next->next)
		current = current->next;
	second_last = current;
	current = current->next;
	second_last->next = NULL;
	current->next = b->top;
	b->top = current;
}

//rrr: rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}