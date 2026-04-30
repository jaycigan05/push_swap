/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:47:11 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack *a, t_stack *b)
{
	t_node	**lis_nodes;
	int		lis_size;
	int		initial_size;
	int		position;

	assign_index(a);
	lis_nodes = build_lis_set(a, &lis_size);
	if (!lis_nodes)
		return ;
	initial_size = a->size;
	position = 0;
	while (position < initial_size)
	{
		if (!is_node_in_set(a->top, lis_nodes, lis_size))
			pb(a, b);
		else
			ra(a);
		position++;
	}
	while (b->size > 0)
		move_best_node(a, b);
	rotate_a_to_min(a);
	free(lis_nodes);
}
