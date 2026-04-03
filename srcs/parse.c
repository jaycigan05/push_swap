/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:51:09 by jagan             #+#    #+#             */
/*   Updated: 2026/03/26 17:31:45 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Check if a string is a valid integer (with optional + / - sign)
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
}//需要搞清楚0和1的差别,确认第3个if是不是check如果只是一个symbol而已

// Convert string to long (to check for overflow)
static long	ft_atol(const char *str)
{
	long	result;
	int	sign;
	int	i;
	
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
}//check its difference with atoi

// Check if the value is within int range
static int	is_in_int_range(long value)
{
	return (value >= INT_MIN && value <= INT_MAX);
} //check the value of intmin and int max

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

// Parse arguments and build stack A
t_stack *parse_args(int argc, char **argv)
{
	t_stack	*stack;
	t_node	*node;
	long	value;
	int	i;

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
		if (!is_in_int_range(value))
		{
			free_stack(stack);
			return (NULL);
		}
		node = create_node((int)value); //为什么int?为什么不能用回原本的long?
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
}//what does it mean by parse??
