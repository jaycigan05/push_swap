/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:22:20 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 10:43:47 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_stack *a)
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
}

void	do_rotate_b(t_stack *b)
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
}

void	do_rrotate_a(t_stack *a)
{
	t_node	*current;
	t_node	*second_last;

	if (!a || a->size < 2)
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
}

void	do_rrotate_b(t_stack *b)
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