/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_lis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:43:30 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 12:43:36 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	**build_lis_set(t_stack *a, int *lis_size)
{
	t_lis	lis;
	t_node	**res;

	lis.size = a->size;
	lis.nodes = copy_stack_nodes(a);
	if (!lis.nodes)
		return (NULL);
	lis.dp = malloc(sizeof(int) * lis.size);
	lis.prev = malloc(sizeof(int) * lis.size);
	if (!lis.dp || !lis.prev)
	{
		free(lis.nodes);
		free(lis.dp);
		free(lis.prev);
		return (NULL);
	}
	init_lis_arrays(&lis);
	lis.best_end = 0;
	compute_lis(&lis);
	res = extract_lis(&lis, lis_size);
	free(lis.nodes);
	free(lis.dp);
	free(lis.prev);
	return (res);
}
