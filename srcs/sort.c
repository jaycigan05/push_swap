/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 05:18:30 by jagan             #+#    #+#             */
/*   Updated: 2026/04/04 06:29:37 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Hanlde 2 elements
static void	sort_two(t_stack *a)
{
	if (peek_top(a)->value > peek_second(a)->value)
		sa(a);
}

// Handle 3 elements
static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	
	first = peek_top(a)->value;
	second = peek_second(a)->value;
	third = peek_top(a)->next->next->value;
	if (first > second && second < third && first < third) //eg: 213
		sa(a);
	else if (first > second && second > third) // eg: 321
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && first < third) //eg: 132
	{
		rra(a);
		sa(a);
	}
	else if (first < second && second > third) //eg: 231
		rra(a);
	else if (first > second && second < third && first > third) //eg: 312
		ra(a);
}
