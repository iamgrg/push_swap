/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_comb_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:07:23 by gansard           #+#    #+#             */
/*   Updated: 2023/03/12 11:08:56 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_moves(t_move *move, char *name)
{
	move->rank = -1;
	move->times = -1;
	move->name = name;
	return (1);
}

int	ft_set_combs(t_combs *combs)
{
	int	res;

	res = 1;
	res = ft_set_moves(combs->pb, "pb");
	if (!res)
		return (0);
	res = ft_set_moves(combs->ra, "ra");
	if (!res)
		return (0);
	res = ft_set_moves(combs->rb, "rb");
	if (!res)
		return (0);
	res = ft_set_moves(combs->rr, "rr");
	if (!res)
		return (0);
	res = ft_set_moves(combs->rra, "rra");
	if (!res)
		return (0);
	res = ft_set_moves(combs->rrb, "rrb");
	if (!res)
		return (0);
	res = ft_set_moves(combs->rrr, "rrr");
	if (!res)
		return (0);
	return (1);
}

t_combs	*ft_create_combs(void)
{
	t_combs	*combs;

	combs = malloc(sizeof(t_combs));
	if (!combs)
		return (NULL);
	combs->pb = malloc(sizeof(t_move));
	combs->ra = malloc(sizeof(t_move));
	combs->rb = malloc(sizeof(t_move));
	combs->rr = malloc(sizeof(t_move));
	combs->rra = malloc(sizeof(t_move));
	combs->rrb = malloc(sizeof(t_move));
	combs->rrr = malloc(sizeof(t_move));
	if (!combs->rrr || !combs->rrb || !combs->rr || !combs->rra || !combs->pb
		|| !combs->ra || !combs->rb || !ft_set_combs(combs))
		return (ft_free_combs(combs), NULL);
	return (combs);
}
