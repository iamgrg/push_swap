/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:09:44 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 11:10:49 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_up_or_down(int nb1, int nb2, char c)
{
	if (c == 'b')
		return (nb1 <= nb2);
	else
		return (nb1 >= nb2);
}

int	ft_solve_pos(t_stack *cur, int nb, char c)
{
	if (ft_up_or_down(nb, cur->content, c))
	{
		if (!cur->next || cur->content != cur->next->content)
			return (1);
	}
	return (0);
}

int	ft_pos_in_b(int nb, t_stack **stack)
{
	long unsigned int	min_dif;
	long unsigned int	c_dif;
	int					i;
	int					pos_p;
	t_stack				*c;

	i = 0;
	pos_p = i;
	min_dif = UINT_MAX;
	c = (*stack);
	while (c)
	{
		if (nb > c->content)
			c_dif = ft_abs((nb - c->content));
		else
			c_dif = ft_abs((c->content - nb));
		if (c_dif < min_dif)
		{
			min_dif = c_dif;
			pos_p = i + ft_solve_pos(c, nb, 'b');
		}
		c = c->next;
		i++;
	}
	return (pos_p);
}

int	ft_pos_in_a(int nb, t_stack **stack)
{
	long unsigned int	min_dif;
	long unsigned int	c_dif;
	int					i;
	int					pos_p;
	t_stack				*c;

	i = 0;
	pos_p = i;
	min_dif = UINT_MAX;
	c = (*stack);
	while (c)
	{
		if (nb > c->content)
			c_dif = ft_abs((nb - c->content));
		else
			c_dif = ft_abs((c->content - nb));
		if (c_dif < min_dif)
		{
			min_dif = c_dif;
			pos_p = i + ft_solve_pos(c, nb, 'a');
		}
		c = c->next;
		i++;
	}
	return (pos_p);
}
