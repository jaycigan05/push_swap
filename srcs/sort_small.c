/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 10:41:58 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (peek_top(a)->value > peek_second(a)->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = peek_top(a)->value;
	mid = peek_second(a)->value;
	bot = a->top->next->next->value;
	if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (top > mid && top < bot)
		sa(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}