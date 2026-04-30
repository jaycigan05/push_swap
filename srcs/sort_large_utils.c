/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:43:47 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	**copy_stack_nodes(t_stack *a)
{
	t_node	**nodes;
	t_node	*current;
	int		size;
	int		i;

	size = a->size;
	nodes = (t_node **)malloc(sizeof(t_node *) * size);
	if (!nodes)
		return (NULL);
	current = a->top;
	i = 0;
	while (i < size)
	{
		nodes[i] = current;
		current = current->next;
		i++;
	}
	return (nodes);
}

static void	init_lis_arrays(int *dp, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static void	fill_lis_data(t_node **nodes, int *dp, int *prev, int size,
	int *best_end)
{
	int	i;
	int	j;
	int	best_length;

	i = 0;
	best_length = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (nodes[j]->index < nodes[i]->index && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		if (dp[i] > best_length)
		{
			best_length = dp[i];
			*best_end = i;
		}
		i++;
	}
}

static t_node	**extract_lis_nodes(t_node **nodes, int *prev, int best_end,
	int size, int *lis_size)
{
	t_node	**lis;
	int		length;
	int		i;

	lis = (t_node **)malloc(sizeof(t_node *) * size);
	if (!lis)
		return (NULL);
	length = 0;
	i = best_end;
	while (i != -1)
	{
		lis[length] = nodes[i];
		length++;
		i = prev[i];
	}
	*lis_size = length;
	return (lis);
}

t_node	**build_lis_set(t_stack *a, int *lis_size)
{
	t_node	**nodes;
	t_node	**lis;
	int		*dp;
	int		*prev;
	int		best_end;

	nodes = copy_stack_nodes(a);
	if (!nodes)
		return (NULL);
	dp = (int *)malloc(sizeof(int) * a->size);
	prev = (int *)malloc(sizeof(int) * a->size);
	if (!dp || !prev)
	{
		free(nodes);
		free(dp);
		free(prev);
		return (NULL);
	}
	init_lis_arrays(dp, prev, a->size);
	best_end = 0;
	fill_lis_data(nodes, dp, prev, a->size, &best_end);
	lis = extract_lis_nodes(nodes, prev, best_end, a->size, lis_size);
	free(nodes);
	free(dp);
	free(prev);
	return (lis);
}
