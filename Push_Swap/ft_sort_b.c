/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// -------------------------PROTOTYPE--------------------------
// ------------------------------------------------------------

t_stack	*ft_sort_b(t_stack **a)
{
	t_stack		*b;

	b = NULL;
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_sort_b_next(a, &b);
	if (!ft_issorted(*a))
		ft_sort_three(a);
	return (b);
}

void	ft_sort_b_next(t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*tmp;

	while (ft_list_size(*a) > 3 && !ft_issorted(*a))
	{
		tmp = *a;
		i = ft_rotate_type_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (i == ft_case_rrarrb(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_case_rarrb(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_case_rrarb(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int			i;
	t_stack		*tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->nbr))
			i = ft_case_rarb(a, b, tmp->nbr);
		if (i > ft_case_rrarrb(a, b, tmp->nbr))
			i = ft_case_rrarrb(a, b, tmp->nbr);
		if (i > ft_case_rarrb(a, b, tmp->nbr))
			i = ft_case_rarrb(a, b, tmp->nbr);
		if (i > ft_case_rrarb(a, b, tmp->nbr))
			i = ft_case_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
