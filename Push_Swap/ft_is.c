/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Calculates the minimum number of movements.                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// --------------------------PROTOTYPE-----------------------------
int		ft_is_rr(t_stack *a, t_stack *b, int c, char s);
int		ft_is_rrr(t_stack *a, t_stack *b, int c, char s);
int		ft_is_rarrb(t_stack *a, t_stack *b, int c, char s);
int		ft_is_rrarb(t_stack *a, t_stack *b, int c, char s);
// ----------------------------------------------------------------

int	ft_is_rr(t_stack *a, t_stack *b, int c, char s)
{
	int		i;

	i = 0;
	if (s == 'a')
	{
		i = ft_find_place_a(a, c);
		if (i < ft_find_index(b, c))
			i = ft_find_index(b, c);
	}
	if (s == 'b')
	{
		i = ft_find_place_b(b, c);
		if (i < ft_find_index(a, c))
			i = ft_find_index(a, c);
	}
	return (i);
}

int	ft_is_rrr(t_stack *a, t_stack *b, int c, char s)
{
	int		i;

	i = 0;
	if (s == 'a')
	{
		if (ft_find_place_a(a, c))
			i = ft_list_size(a) - ft_find_place_a(a, c);
		if ((i < (ft_list_size(b) - ft_find_index(b, c)))
			&& ft_find_index(b, c))
			i = ft_list_size(b) - ft_find_index(b, c);
	}
	if (s == 'b')
	{
		if (ft_find_place_b(b, c))
			i = ft_list_size(b) - ft_find_place_b(b, c);
		if ((i < (ft_list_size(a) - ft_find_index(a, c)))
			&& ft_find_index(a, c))
			i = ft_list_size(a) - ft_find_index(a, c);
	}
	return (i);
}

int	ft_is_rarrb(t_stack *a, t_stack *b, int c, char s)
{
	int		i;

	i = 0;
	if (s == 'a')
	{
		if (ft_find_index(b, c))
			i = ft_list_size(b) - ft_find_index(b, c);
		i = ft_find_place_a(a, c) + i;
	}
	if (s == 'b')
	{
		if (ft_find_place_b(b, c))
			i = ft_list_size(b) - ft_find_place_b(b, c);
		i = ft_find_index(a, c) + i;
	}
	return (i);
}

int	ft_is_rrarb(t_stack *a, t_stack *b, int c, char s)
{
	int		i;

	i = 0;
	if (s == 'a')
	{
		if (ft_find_place_a(a, c))
			i = ft_list_size(a) - ft_find_place_a(a, c);
		i = ft_find_index(b, c) + i;
	}
	if (s == 'b')
	{
		if (ft_find_index(a, c))
			i = ft_list_size(a) - ft_find_index(a, c);
		i = ft_find_place_b(b, c) + i;
	}
	return (i);
}
