/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:28:51 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 11:36:49 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_roll_util(t_stack **stack, int i, int len, char c)
{
	int	j;
	int	rev;

	j = 0;
	rev = 0;
	if (i == len)
		return ;
	if (i > len / 2)
	{
		i = len - i;
		rev = 1;
	}
	while (j < i)
	{
		if (rev)
			ft_rev(stack, c);
		else
			ft_r(stack, c);
		j++;
	}
}

void	ft_roll(t_stack **stack, char c)
{
	t_stack	*current;
	int		i;
	int		len;

	i = 0;
	len = ft_stacklen(stack);
	current = (*stack);
	while (current->next && (current->content) >= (current->next->content))
	{
		current = current->next;
		i++;
	}
	i++;
	ft_roll_util(stack, i, len, c);
}

void	ft_rev_roll(t_stack **stack, char c)
{
	t_stack	*current;
	int		i;
	int		len;

	i = 0;
	len = ft_stacklen(stack);
	current = (*stack);
	while (current->next && (current->content) <= (current->next->content))
	{
		current = current->next;
		i++;
	}
	i++;
	ft_roll_util(stack, i, len, c);
}

int	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	nb;
	int	pos_a;

	while (ft_stacklen(stack_b) > 0)
	{
		i = 0;
		nb = (*stack_b)->content;
		pos_a = ft_pos_in_a(nb, stack_a);
		while (i < pos_a && !(pos_a == ft_stacklen(stack_a)))
		{
			ft_r(stack_a, 'a');
			i++;
		}
		ft_p(stack_b, stack_a, 'a');
	}
	ft_rev_roll(stack_a, 'a');
	return (0);
}
