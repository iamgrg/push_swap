/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:07:43 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 13:59:04 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack **stack)
{
	int		stack_len;
	t_stack	*current;

	stack_len = 0;
	current = (*stack);
	while (current)
	{
		current = current->next;
		stack_len++;
	}
	return (stack_len);
}

int	set_mv(t_move *move, int times, int r)
{
	move->times = times;
	move->rank = r++;
	return (r);
}

int	set_top(t_combs *combs, int pos_a, int pos_b, t_len *ln)
{
	int	r;

	r = 0;
	if (pos_b > ln->b / 2)
	{
		r = set_mv(combs->rrr, ft_ct_smart_mv(pos_a, pos_b, ln->a, ln->b), r);
		if (ln->b - pos_b > (ln->a - pos_a))
			r = set_mv(combs->rrb, ln->b - pos_b - (ln->a - pos_a), r);
		else
			r = set_mv(combs->rra, ln->a - pos_a - (ln->b - pos_b), r);
	}
	else
	{
		r = set_mv(combs->rra, ln->a - pos_a, r);
		r = set_mv(combs->rb, pos_b, r);
	}
	return (r);
}

int	set_low(t_combs *combs, int pos_a, int pos_b, t_len *ln)
{
	int	r;

	r = 0;
	if (pos_b <= ln->b / 2)
	{
		r = set_mv(combs->rr, ft_ct_smart_mv(pos_a, pos_b, ln->a, ln->b), r);
		if (pos_b > pos_a)
			r = set_mv(combs->rb, pos_b - pos_a, r);
		else
			r = set_mv(combs->ra, pos_a - pos_b, r);
	}
	else
	{
		r = set_mv(combs->ra, pos_a, r);
		r = set_mv(combs->rrb, ln->b - pos_b, r);
	}
	return (r);
}

t_combs	*ft_find_comb(t_el *el, t_combs *combs, t_stack **stack_a,
		t_stack **stack_b)
{
	int		pos_b;
	t_len	*ln;
	int		r;

	r = 0;
	pos_b = ft_pos_in_b(el->value, stack_b);
	ln = malloc(sizeof(int) * 2);
	if (!ln)
		return (NULL);
	ln->a = ft_stacklen(stack_a);
	ln->b = ft_stacklen(stack_b);
	if (el->pos > ln->a / 2)
		r = set_top(combs, el->pos, pos_b, ln);
	if (el->pos <= ln->a / 2)
		r = set_low(combs, el->pos, pos_b, ln);
	r = set_mv(combs->pb, 1, r);
	free(ln);
	return (combs);
}
