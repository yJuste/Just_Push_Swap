/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// ------------------------------PROTOTYPE-------------------------------
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
// ----------------------------------------------------------------------

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b);
		while ((*b)->nbr != c)
			ft_rb(b);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	if (s == 'b')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b);
		while ((*a)->nbr != c)
			ft_ra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b);
		while ((*b)->nbr != c)
			ft_rrb(b);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a);
		ft_pa(a, b);
	}
	if (s == 'b')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b);
		while ((*a)->nbr != c)
			ft_rra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a);
		while ((*b)->nbr != c)
			ft_rb(b);
		ft_pa(a, b);
	}
	if (s == 'b')
	{
		while ((*a)->nbr != c)
			ft_rra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a);
		while ((*b)->nbr != c)
			ft_rrb(b);
		ft_pa(a, b);
	}
	if (s == 'b')
	{
		while ((*a)->nbr != c)
			ft_ra(a);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b);
		ft_pb(a, b);
	}
	return (-1);
}
