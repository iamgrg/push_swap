/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:00:58 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 12:03:34 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ct_smart_mv(int pos_a, int pos_b, int stacklen_a, int stacklen_b)
{
	if (pos_a <= stacklen_a / 2)
	{
		if (pos_a > pos_b)
			return (pos_b);
		else
			return (pos_a);
	}
	else
	{
		if (stacklen_a - pos_a > stacklen_b - pos_b)
			return (stacklen_b - pos_b);
		else
			return (stacklen_a - pos_a);
	}
}

int	ft_compare(int pos_a, int pos_b, int stacklen_a, int stacklen_b)
{
	if (pos_a <= stacklen_a / 2)
	{
		if (pos_a > pos_b)
			return (pos_a);
		else
			return (pos_b);
	}
	else
	{
		if (stacklen_a - pos_a > stacklen_b - pos_b)
			return (stacklen_a - pos_a);
		else
			return (stacklen_b - pos_b);
	}
}

int	ft_nb_rotate(int pos_a, int pos_b, int len_stack_a, int len_stack_b)
{
	int	nb_rotate;

	if (pos_a > len_stack_a / 2)
	{
		if (pos_b > len_stack_b / 2)
			nb_rotate = ft_compare(pos_a, pos_b, len_stack_a, len_stack_b);
		else
			nb_rotate = (len_stack_a - pos_a) + pos_b;
	}
	if (pos_a <= len_stack_a / 2)
	{
		if (pos_b <= len_stack_b / 2)
			nb_rotate = ft_compare(pos_a, pos_b, len_stack_a, len_stack_b);
		else
			nb_rotate = (len_stack_b - pos_b) + pos_a;
	}
	return (nb_rotate);
}

int	ft_count_moves(int nb, int pos_a, t_stack **stack_a, t_stack **stack_b)
{
	int		pos_b;
	int		len_stack_a;
	int		len_stack_b;
	t_stack	*current;

	len_stack_a = 0;
	current = (*stack_a);
	while (current)
	{
		current = current->next;
		len_stack_a++;
	}
	current = (*stack_b);
	len_stack_b = 0;
	while (current)
	{
		current = current->next;
		len_stack_b++;
	}
	pos_b = ft_pos_in_b(nb, stack_b);
	return (ft_nb_rotate(pos_a, pos_b, len_stack_a, len_stack_b) + 1);
}

t_el	*ft_wich_el_mv(t_el *el, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		pos_a;
	int		cur_mv;
	int		nb_min_mv;

	pos_a = 0;
	current = (*stack_a);
	nb_min_mv = ft_count_moves(current->content, pos_a, stack_a, stack_b);
	el->pos = pos_a;
	el->value = current->content;
	current = current->next;
	pos_a++;
	while (current)
	{
		cur_mv = ft_count_moves(current->content, pos_a, stack_a, stack_b);
		if (cur_mv < nb_min_mv)
		{
			nb_min_mv = cur_mv;
			el->pos = pos_a;
			el->value = current->content;
		}
		current = current->next;
		pos_a++;
	}
	return (el);
}
