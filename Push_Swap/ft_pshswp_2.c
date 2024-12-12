/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pshswp_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Main function that calls every other one.                              */
/* ************************************************************************** */
#include "ft_pshswp.h"

// --------------------------PROTOTYPE---------------------------
void		ft_sort(t_stack **a);
void		ft_sort_three(t_stack **a);
int			ft_parse(t_stack *a, t_stack *b, char s);
// --------------------------------------------------------------

void	ft_sort(t_stack **a)
{
	int			i;
	t_flag		flg;
	t_stack		*b;

	b = NULL;
	flg.a = 'a';
	flg.b = 'b';
	if (ft_list_size(*a) == 2)
		ft_sa(a, 0);
	if (ft_list_size(*a) == 3)
		ft_sort_three(a);
	else
	{
		b = ft_sort_b(&flg, a);
		a = ft_sort_a(&flg, a, &b);
		i = ft_find_index(*a, ft_list_min(*a));
		if (i < ft_list_size(*a) - i)
			while ((*a)->nbr != ft_list_min(*a))
				ft_ra(a, 0);
		else
			while ((*a)->nbr != ft_list_min(*a))
				ft_rra(a, 0);
	}
	return ;
}

void	ft_sort_three(t_stack **a)
{
	if (ft_list_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_list_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_issorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_list_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

int	ft_parse(t_stack *a, t_stack *b, char s)
{
	int			i;
	t_stack		*tmp;

	if (s == 'a')
		tmp = b;
	else
		tmp = a;
	if (s == 'a')
		i = ft_is_rrr(a, b, b->nbr, 'a');
	else
		i = ft_is_rrr(a, b, a->nbr, 'b');
	while (tmp)
	{
		if (i > ft_is_rr(a, b, tmp->nbr, s))
			i = ft_is_rr(a, b, tmp->nbr, s);
		if (i > ft_is_rrr(a, b, tmp->nbr, s))
			i = ft_is_rrr(a, b, tmp->nbr, s);
		if (i > ft_is_rarrb(a, b, tmp->nbr, s))
			i = ft_is_rarrb(a, b, tmp->nbr, s);
		if (i > ft_is_rrarb(a, b, tmp->nbr, s))
			i = ft_is_rrarb(a, b, tmp->nbr, s);
		tmp = tmp->next;
	}
	return (i);
}
