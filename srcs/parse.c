/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:51:09 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 10:40:30 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_integer(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	t_node	*node;
	long	value;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer(argv[i]))
		{
			free_stack(stack);
			return (NULL);
		}
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			free_stack(stack);
			return (NULL);
		}
		node = create_node((int)value);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		push_node(stack, node);
		i--;
	}
	if (has_duplicates(stack))
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}