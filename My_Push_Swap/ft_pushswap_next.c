/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Algorithm for pushswap.                                                */
/* ************************************************************************** */
#include "ft_pushswap.h"

// ---------------------------------PROTOTYPE---------------------------------
void		ft_sort(t_stack **a, int reverse);
void		ft_sort_list(t_stack **a, t_stack **b);
int			ft_sort_list_next(t_stack *b, int *reverse, int *min);
void		ft_sort_three(t_stack **a);
// ---------------------------------------------------------------------------

void	ft_sort(t_stack **a, int reverse)
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
		while (*a)
			ft_pb(a, &b, 0);
		ft_sort_list(a, &b);
		i = ft_find_index(*a, ft_list_min(*a));
		if (i > ft_list_size(*a) - ft_find_index(*a, ft_list_min(*a)))
		{
			i = ft_list_size(*a) - ft_find_index(*a, ft_list_min(*a));
			reverse = 1;
		}
		while ((*a)->nbr != ft_list_min(*a) && !reverse)
			ft_ra(a, 0);
		while ((*a)->nbr != ft_list_min(*a) && reverse)
			ft_rra(a, 0);
	}
}

void	ft_sort_list(t_stack **a, t_stack **b)
{
	int			i;
	int			min;
	int			reverse;

	i = 0;
	min = 0;
	reverse = 0;
	while (*b)
	{
		i = ft_sort_list_next(*b, &reverse, &min);
		while (i > 0)
		{
			if (reverse == 0)
				ft_rb(b, 0);
			else
				ft_rrb(b, 0);
			i--;
		}
		ft_pa(a, b, 0);
		if (min == 1)
			ft_ra(a, 0);
		min = 0;
		reverse = 0;
	}
}

int	ft_sort_list_next(t_stack *b, int *reverse, int *min)
{
	int			i;

	i = ft_list_size(b);
	if (i > ft_find_index(b, ft_list_max(b)))
		i = ft_find_index(b, ft_list_max(b));
	if (i > ft_list_size(b) - ft_find_index(b, ft_list_max(b)))
	{
		i = ft_list_size(b) - ft_find_index(b, ft_list_max(b));
		*reverse = 1;
		*min = 0;
	}
	if (i > ft_find_index(b, ft_list_min(b)))
	{
		i = ft_find_index(b, ft_list_min(b));
		*min = 1;
		*reverse = 0;
	}
	if (i > ft_list_size(b) - ft_find_index(b, ft_list_min(b)))
	{
		i = ft_list_size(b) - ft_find_index(b, ft_list_min(b));
		*reverse = 1;
		*min = 1;
	}
	return (i);
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
