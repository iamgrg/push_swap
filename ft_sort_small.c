/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:06:57 by gansard           #+#    #+#             */
/*   Updated: 2023/03/10 19:06:58 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cut_cut(t_stack **s)
{
	if ((*s)->content < (*s)->next->next->content)
		ft_s(s, 'a');
	else
	{
		if ((*s)->next->content > (*s)->next->next->content)
		{
			ft_r(s, 'a');
			ft_s(s, 'a');
		}
		else
			ft_r(s, 'a');
	}
}

void	ft_ssmall(t_stack **s)
{
	if (ft_stacklen(s) > 1)
	{
		if (((*s)->content > (*s)->next->content))
			ft_r(s, 'a');
	}
}

int	ft_sort_small(t_stack **s)
{
	if (ft_stacklen(s) < 3)
		return (ft_ssmall(s), 0);
	if ((*s)->content < (*s)->next->content)
	{
		if ((*s)->content < (*s)->next->next->content)
		{
			if ((*s)->next->content < (*s)->next->next->content)
				return (0);
			else
				return (ft_rev(s, 'a'), ft_s(s, 'a'), 0);
		}
		if ((*s)->content > (*s)->next->next->content)
		{
			if ((*s)->next->content < (*s)->next->next->content)
				return (ft_s(s, 'a'), 0);
			else
				return (ft_rev(s, 'a'), 0);
		}
	}
	else
		ft_cut_cut(s);
	return (0);
}
