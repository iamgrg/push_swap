/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:39:56 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 18:10:27 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(long int content)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

int	ft_check_min_max(t_stack **stack)
{
	t_stack	*c;

	c = (*stack);
	while (c->next)
	{
		if (c->next->content > 2147483647 || c->content > 2147483647
			|| c->content < -2147483648 || c->next->content < -2147483648)
			return (0);
		c = c->next;
	}
	return (1);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*current;
	int		i;

	i = 1;
	stack_a = ft_stacknew(ft_long_atoi(av[i++]));
	if (!stack_a)
		return (NULL);
	current = stack_a;
	while (i < ac)
	{
		current->next = ft_stacknew(ft_long_atoi(av[i]));
		if (!current->next)
			return (ft_free_stack(&stack_a), NULL);
		current = current->next;
		i++;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*current;

	if (ac < 2)
		return (ft_printf("error\nInvalid number of args.\n"), 0);
	if (ft_nan(av))
		return (ft_printf("error\nAll args are not numbers.\n"), 0);
	stack_a = ft_create_stack(ac, av);
	if (!stack_a)
		return (0);
	if (ft_check_double(&stack_a) || !ft_check_min_max(&stack_a))
		return (ft_printf("error\nInvalid args\n"),
			ft_free_stack(&stack_a),
			0);
	if (ft_check_order(&stack_a))
		return (ft_free_stack(&stack_a), 0);
	if (!stack_a)
		return (ft_printf("err\n"), 0);
	ft_sort(&stack_a);
}
