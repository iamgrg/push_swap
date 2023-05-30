/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:18:50 by gansard           #+#    #+#             */
/*   Updated: 2023/03/10 19:13:35 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_rev(stack_a, '0') || !ft_rev(stack_b, '0'))
		return (0);
	ft_printf("rrr\n");
	return (1);
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_r(stack_a, '0') || !ft_r(stack_b, '0'))
		return (0);
	ft_printf("rr\n");
	return (1);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_s(stack_b, '0'))
		return (printf("b\n"), '0');
	if (!ft_s(stack_a, '0'))
		return (printf("a\n"), '0');
	ft_printf("ss\n");
	return (1);
}

int	ft_triger(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str, "pb") == 0)
		return (ft_p(stack_a, stack_b, 'b'));
	if (ft_strcmp(str, "ra") == 0)
		return (ft_r(stack_a, 'a'));
	if (ft_strcmp(str, "rb") == 0)
		return (ft_r(stack_b, 'b'));
	if (ft_strcmp(str, "rra") == 0)
		return (ft_rev(stack_a, 'a'));
	if (ft_strcmp(str, "rrb") == 0)
		return (ft_rev(stack_b, 'b'));
	if (ft_strcmp(str, "rr") == 0)
		return (ft_rr(stack_a, stack_b));
	if (ft_strcmp(str, "rrr") == 0)
		return (ft_rrr(stack_a, stack_b));
	if (ft_strcmp(str, "ss") == 0)
		return (ft_ss(stack_a, stack_b));
	else
		return (0);
}
