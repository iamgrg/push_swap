/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:35:44 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 16:31:35 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cdu(int nb, t_stack **stack)
{
	t_stack	*c;
	int		count;

	count = 0;
	c = (*stack);
	while (c)
	{
		if (nb == c->content)
		{
			count++;
			if (count == 2)
				return (1);
		}
		c = c->next;
	}
	return (0);
}

int	ft_check_double(t_stack **stack)
{
	t_stack	*c;

	c = (*stack);
	while (c)
	{
		if (ft_cdu(c->content, stack))
			return (1);
		c = c->next;
	}
	return (0);
}

int	ft_nanutil(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_nan(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		if (ft_nanutil(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_order(t_stack **stack)
{
	t_stack	*c;

	c = (*stack);
	while (c->next)
	{
		if (c->content > c->next->content)
			return (0);
		c = c->next;
	}
	return (1);
}
