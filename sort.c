/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:40:01 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 18:46:50 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_print_combs(t_combs *combs)
//{
//	ft_printf("-------------------------------------\n");
//	ft_printf("%s  | %d  | %d\n", combs->pb->name, combs->pb->rank,
//			combs->pb->times);
//	ft_printf("%s  | %d  | %d\n", combs->ra->name, combs->ra->rank,
//			combs->ra->times);
//	ft_printf("%s  | %d  | %d\n", combs->rb->name, combs->rb->rank,
//			combs->rb->times);
//	ft_printf("%s  | %d  | %d\n", combs->rr->name, combs->rr->rank,
//			combs->rr->times);
//	ft_printf("%s | %d  | %d\n", combs->rra->name, combs->rra->rank,
//			combs->rra->times);
//	ft_printf("%s | %d  | %d\n", combs->rrb->name, combs->rrb->rank,
//			combs->rrb->times);
//	ft_printf("%s | %d  | %d\n", combs->rrr->name, combs->rrr->rank,
//			combs->rrr->times);
//}

//void	ft_printf_stacks(t_stack **stack_a, t_stack **stack_b)
//{
//	t_stack	*current;

//	ft_printf("_____________________________________\n");
//	ft_printf("STACK A : \n");
//	current = (*stack_a);
//	while (current)
//	{
//		ft_printf("%d\n", current->content);
//		current = current->next;
//	}
//	ft_printf("-------------------------------------\n");
//	ft_printf("STACK B : \n");
//	current = (*stack_b);
//	while (current)
//	{
//		ft_printf("%d\n", current->content);
//		current = current->next;
//	}
//	ft_printf("_____________________________________\n");
//}

t_move	*ft_next_move(t_combs *combs, int rank)
{
	if (combs->pb->rank == rank)
		return (combs->pb);
	if (combs->ra->rank == rank)
		return (combs->ra);
	if (combs->rb->rank == rank)
		return (combs->rb);
	if (combs->rr->rank == rank)
		return (combs->rr);
	if (combs->rra->rank == rank)
		return (combs->rra);
	if (combs->rrb->rank == rank)
		return (combs->rrb);
	if (combs->rrr->rank == rank)
		return (combs->rrr);
	else
		return (NULL);
}

int	ft_move_el(t_combs *combs, t_stack **stack_a, t_stack **stack_b)
{
	t_move	*move_now;
	int		rank;

	rank = 0;
	move_now = ft_next_move(combs, rank);
	while (move_now)
	{
		while (move_now->times)
		{
			if (!ft_triger(move_now->name, stack_a, stack_b))
				return (0);
			move_now->times--;
		}
		rank++;
		move_now = ft_next_move(combs, rank);
	}
	return (1);
}

int	ft_srtloop(t_el *el, t_stack **stack1, t_stack **stack2, t_combs *combs)
{
	el = ft_wich_el_mv(el, stack1, stack2);
	if (!el)
		return (0);
	combs = ft_find_comb(el, combs, stack1, stack2);
	if (!combs)
		return (0);
	if (!ft_move_el(combs, stack1, stack2))
		return (0);
	ft_set_combs(combs);
	return (1);
}

int	ft_finish(t_stack **stack_a, t_stack **stack_b, t_el *el, t_combs *combs)
{
	int	len;

	if (ft_stacklen(stack_b) <= 2)
		return (ft_sort_five(stack_a, stack_b), 0);
	while (ft_stacklen(stack_a) > 1)
		ft_srtloop(el, stack_a, stack_b, combs);
	ft_roll(stack_b, 'b');
	ft_p(stack_b, stack_a, 'a');
	ft_ssmall(stack_a);
	el->value = (*stack_a)->content;
	el->pos = 0;
	ft_set_combs(combs);
	combs = ft_find_comb(el, combs, stack_a, stack_b);
	if (!combs)
		return (printf("2\n"), 0);
	if (!ft_move_el(combs, stack_a, stack_b))
		return (printf("3\n"), 0);
	ft_roll(stack_b, 'b');
	len = ft_stacklen(stack_b);
	while (len--)
		ft_p(stack_b, stack_a, 'a');
	return (1);
}

int	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_combs	*combs;
	int		i;
	t_el	*el;

	combs = ft_create_combs();
	stack_b = NULL;
	if (!combs)
		return (ft_free_all(combs, stack_a, &stack_b, NULL), 0);
	stack_b = NULL;
	i = 0;
	while (ft_stacklen(stack_a) > 3 && i++ < 2)
		ft_triger("pb", stack_a, &stack_b);
	el = malloc(sizeof(t_el));
	if (!el)
		return (ft_free_all(combs, stack_a, &stack_b, NULL), 0);
	while (ft_stacklen(stack_a) > 3)
		ft_srtloop(el, stack_a, &stack_b, combs);
	ft_sort_small(stack_a);
	if (ft_stacklen(&stack_b) > 0)
		ft_finish(stack_a, &stack_b, el, combs);
	ft_free_all(combs, stack_a, &stack_b, el);
	return (0);
}
