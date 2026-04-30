/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:43:40 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (position - size);
}

int	get_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (cost_a < 0)
			cost_a = -cost_a;
		if (cost_b < 0)
			cost_b = -cost_b;
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	return (cost_a + cost_b);
}
