/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_lis_core.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:46:44 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:46:46 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**copy_stack_nodes(t_stack *a)
{
	t_node	**nodes;
	t_node	*cur;
	int		i;

	nodes = malloc(sizeof(t_node *) * a->size);
	if (!nodes)
		return (NULL);
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		nodes[i++] = cur;
		cur = cur->next;
	}
	return (nodes);
}

void	init_lis_arrays(t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->size)
	{
		lis->dp[i] = 1;
		lis->prev[i] = -1;
		i++;
	}
}

static void	update_best(t_lis *lis, int i, int *best)
{
	if (lis->dp[i] > *best)
	{
		*best = lis->dp[i];
		lis->best_end = i;
	}
}

void	compute_lis(t_lis *lis)
{
	int	i;
	int	j;
	int	best;

	i = 0;
	best = 0;
	while (i < lis->size)
	{
		j = 0;
		while (j < i)
		{
			if (lis->nodes[j]->index < lis->nodes[i]->index
				&& lis->dp[j] + 1 > lis->dp[i])
			{
				lis->dp[i] = lis->dp[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		update_best(lis, i, &best);
		i++;
	}
}

t_node	**extract_lis(t_lis *lis, int *size)
{
	t_node	**res;
	int		i;
	int		len;

	res = malloc(sizeof(t_node *) * lis->size);
	if (!res)
		return (NULL);
	len = 0;
	i = lis->best_end;
	while (i != -1)
	{
		res[len++] = lis->nodes[i];
		i = lis->prev[i];
	}
	*size = len;
	return (res);
}
