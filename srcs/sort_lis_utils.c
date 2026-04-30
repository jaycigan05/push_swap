/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:43:29 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_bigger_position(t_stack *a, int index)
{
	t_node	*current;
	int		position;
	int		best_position;
	int		best_bigger;

	current = a->top;
	position = 0;
	best_position = -1;
	best_bigger = INT_MAX;
	while (current)
	{
		if (current->index > index && current->index < best_bigger)
		{
			best_bigger = current->index;
			best_position = position;
		}
		current = current->next;
		position++;
	}
	return (best_position);
}

static int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		position;
	int		min_position;
	int		min_index;

	current = a->top;
	position = 0;
	min_position = 0;
	min_index = INT_MAX;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

int	is_node_in_set(t_node *node, t_node **set, int set_size)
{
	int	index;

	index = 0;
	while (index < set_size)
	{
		if (set[index] == node)
			return (1);
		index++;
	}
	return (0);
}

int	get_insert_position(t_stack *a, int index)
{
	int	best_position;

	best_position = find_next_bigger_position(a, index);
	if (best_position != -1)
		return (best_position);
	return (find_min_position(a));
}
