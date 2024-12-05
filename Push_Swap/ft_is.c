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
#include "ft_pshswp.h"

// ------------------------PROTOTYPE------------------------
int		ft_is_rarb(t_stack *a, t_stack *b, int c);
int		ft_is_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_is_rrarb(t_stack *a, t_stack *b, int c);
int		ft_is_rarrb(t_stack *a, t_stack *b, int c);
// ---------------------------------------------------------

int	ft_is_rarb(t_stack *a, t_stack *b, int c)
{
	int		i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

int	ft_is_rrarrb(t_stack *a, t_stack *b, int c)
{
	int		i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

int	ft_is_rrarb(t_stack *a, t_stack *b, int c)
{
	int		i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

int	ft_is_rarrb(t_stack *a, t_stack *b, int c)
{
	int		i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
