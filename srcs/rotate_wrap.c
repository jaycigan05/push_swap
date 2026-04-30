/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	do_rotate_a(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	do_rotate_b(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	do_rotate_a(a);
	do_rotate_b(b);
	write(1, "rr\n", 3);
}
