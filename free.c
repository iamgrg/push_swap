/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:21:59 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 18:50:15 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_combs(t_combs *combs)
{
	if (!combs)
		return ;
	if (combs->pb)
		free(combs->pb);
	if (combs->ra)
		free(combs->ra);
	if (combs->rb)
		free(combs->rb);
	if (combs->rr)
		free(combs->rr);
	if (combs->rra)
		free(combs->rra);
	if (combs->rrb)
		free(combs->rrb);
	if (combs->rrr)
		free(combs->rrr);
	if (combs)
		free(combs);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*temp;

	if (!*stack)
		return ;
	cur = (*stack);
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

void	ft_free_all(t_combs *combs, t_stack **stack_a, t_stack **stack_b,
		t_el *el)
{
	ft_free_combs(combs);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (el)
		free(el);
}
