/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:01:08 by jagan             #+#    #+#             */
/*   Updated: 2026/04/04 04:44:16 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Create a new node
t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

// Push a node onto stack
void	push_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

// Pop a node from stack
t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if(!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	return (node);
}

// Peek at the top of the stack without removing （in stack_ops）
t_node	*peek_top(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top);
}

// Get the second node from top
t_node	*peek_second(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (NULL);
	return (stack->top->next);
}

// Free entire stack
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(stack);
}

// Print error to stderr
void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}//STDERR_FILENO什么意思？

// Check if stack A is sorted in ascending order
int	is_sorted(t_stack *a)
{
	t_node	*current;
	
	if (!a || !a->top)
		return (1);
	current = a->top; //可以思考一下为什么在.h里*next什么意思？可以refer回去pointer
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
