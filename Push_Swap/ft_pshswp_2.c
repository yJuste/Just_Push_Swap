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
#include "ft_pshswp.h"

// -------------------------PROTOTYPE--------------------------
void		ft_sort(t_stack **a);
void		ft_sort_three(t_stack **a);
// ------------------------------------------------------------

void	ft_sort(t_stack **a)
{
	int			i;
	t_stack		*b;

	b = NULL;
	if (ft_list_size(*a) == 2)
		ft_sa(a, 0);
	if (ft_list_size(*a) == 3)
		ft_sort_three(a);
	else
	{
		b = ft_sort_b(a); // trie b
		/*
		a = ft_sort_a(a, &b); // prend b et trie a
		i = ft_find_index(*a, ft_list_min(*a));
		if (i < ft_list_size(*a) - i)
		{
			while ((*a)->nbr != ft_list_min(*a))
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->nbr != ft_list_min(*a))
				ft_rra(a, 0);
		}*/
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
