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

// --------------------------PROTOTYPE--------------------------
t_stack		*ft_sort_b(t_stack **a, t_stack **b);
void		ft_sort_b_next(t_stack **a, t_stack **b);
int			ft_sort_b_parse(t_stack *a, t_stack *b);
int			ft_find_place_b(t_stack *b, int n);
// -------------------------------------------------------------

t_stack	*ft_sort_b(t_stack **a, t_stack **b)
{
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_sort_b_next(a, b);
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
		i = ft_sort_b_parse(*a, *b);
		while (i >= 0)
		{
			if (i == ft_is_rarb(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'b');
			else if (i == ft_is_rrarrb(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_is_rarrb(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_is_rrarb(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
}

int	ft_sort_b_parse(t_stack *a, t_stack *b)
{
	int			i;
	t_stack		*tmp;

	tmp = a;
	i = ft_is_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_is_rarb(a, b, tmp->nbr))
			i = ft_is_rarb(a, b, tmp->nbr);
		if (i > ft_is_rrarrb(a, b, tmp->nbr))
			i = ft_is_rrarrb(a, b, tmp->nbr);
		if (i > ft_is_rarrb(a, b, tmp->nbr))
			i = ft_is_rarrb(a, b, tmp->nbr);
		if (i > ft_is_rrarb(a, b, tmp->nbr))
			i = ft_is_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	ft_find_place_b(t_stack *b, int n)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (n > b->nbr && n < ft_list_last(b)->nbr)
		i = 0;
	else if (n > ft_list_max(b) || n < ft_list_min(b))
		i = ft_find_index(b, ft_list_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < n || tmp->nbr > n)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}
