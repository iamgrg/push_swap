/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:10:46 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 16:45:06 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_stack
{
	long int		content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_move
{
	char			*name;
	int				times;
	int				rank;
}					t_move;

typedef struct s_len
{
	int				a;
	int				b;
}					t_len;

typedef struct s_combs
{
	t_move			*pb;
	t_move			*ra;
	t_move			*rb;
	t_move			*rr;
	t_move			*rra;
	t_move			*rrb;
	t_move			*rrr;
}					t_combs;

typedef struct s_el
{
	int				value;
	int				pos;
}					t_el;

int					ft_check_order(t_stack **stack);
int					ft_check_double(t_stack **stack);
int					ft_nan(char **tab);
void				ft_free_combs(t_combs *combs);
void				ft_free_stack(t_stack **stack);
void				ft_free_all(t_combs *comb, t_stack **stack_a,
						t_stack **stack_b, t_el *el);
int					ft_ct_smart_mv(int pos_a, int pos_b, int stacklen_a,
						int stacklen_b);
int					ft_compare(int pos_a, int pos_b, int stacklen_a,
						int stacklen_b);
int					ft_nb_rotate(int pos_a, int pos_b, int len_stack_a,
						int len_stack_b);
int					ft_count_moves(int nb, int pos_a, t_stack **stack_a,
						t_stack **stack_b);
t_el				*ft_wich_el_mv(t_el *el, t_stack **stack_a,
						t_stack **stack_b);
void				ft_roll(t_stack **stack, char c);
void				ft_rev_roll(t_stack **stack, char c);
int					ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int					ft_pos_in_b(int nb, t_stack **stack);
int					ft_pos_in_a(int nb, t_stack **stack);
int					ft_sort_small(t_stack **stack_a);
void				ft_ssmall(t_stack **s);
int					ft_stacklen(t_stack **stack);
int					ft_sort(t_stack **stack_a);
int					ft_rrr(t_stack **stack_a, t_stack **stack_b);
int					ft_rr(t_stack **stack_a, t_stack **stack_b);
int					ft_ss(t_stack **stack_a, t_stack **stack_b);
int					ft_s(t_stack **stack, char c);
int					ft_p(t_stack **stack1, t_stack **stack2, char c);
int					ft_r(t_stack **stack, char c);
int					ft_rev(t_stack **stack, char c);
t_combs				*ft_create_combs(void);
int					ft_pos_in_b(int nb, t_stack **stack_b);
int					ft_ct_smart_mv(int pos_a, int pos_b, int stacklen_a,
						int stacklen_b);
t_combs				*ft_find_comb(t_el *el, t_combs *combs, t_stack **stack_a,
						t_stack **stack_b);
int					ft_triger(char *str, t_stack **stack_a, t_stack **stack_b);
int					ft_set_combs(t_combs *combs);
#endif