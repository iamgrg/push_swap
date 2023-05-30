/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:18:54 by gansard           #+#    #+#             */
/*   Updated: 2023/03/10 19:06:19 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_s(t_stack **stack, char c)
{
	int	temp;

	if (!*stack)
		return (printf("stack vide pas normal, stack : %c\n", c), 0);
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	return (1);
}

int	ft_p(t_stack **stack1, t_stack **stack2, char c)
{
	t_stack	*temp;

	if (*stack1)
	{
		temp = (*stack1)->next;
		(*stack1)->next = (*stack2);
		(*stack2) = (*stack1);
		(*stack1) = temp;
	}
	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
	return (1);
}

int	ft_r(t_stack **stack, char c)
{
	t_stack	*current;
	t_stack	*temp;

	if (!*stack)
		return (printf("stack vide pas normal\n"), 0);
	current = *stack;
	temp = *stack;
	while (current->next)
		current = current->next;
	(*stack) = (*stack)->next;
	current->next = temp;
	temp->next = NULL;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	return (1);
}

int	ft_rev(t_stack **stack, char c)
{
	t_stack	*current;
	t_stack	*temp;

	if (!*stack)
		return (printf("stack vide pas normal\n"), 0);
	current = *stack;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next->next = (*stack);
	current->next = NULL;
	(*stack) = temp;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	return (1);
}
