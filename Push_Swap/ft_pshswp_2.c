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

void	ft_sort(t_stack **a)
{
	t_stack		*b;
	int			i;

	b = NULL;
	if (ft_list_size(*a) == 2)
		ft_sa(a, 0);
	if (ft_list_size(*a) == 3)
		ft_sort_three(a);
	/*
	else
	{
		b = ft_sort_b(a);
		a = ft_sort_a(a, &b);
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
		}
	}
	*/
}
