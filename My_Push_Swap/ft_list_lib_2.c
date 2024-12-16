/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Second lib for chained list.                                           */
/* ************************************************************************** */
#include "ft_pushswap.h"

// -----------------------PROTOTYPE----------------------
int			ft_find_index(t_stack *a, int n);
int			ft_list_min(t_stack *a);
int			ft_list_max(t_stack *a);
void		ft_list_clear(t_stack **lst);
// ------------------------------------------------------

int	ft_find_index(t_stack *a, int n)
{
	int		i;

	i = 0;
	while (a->nbr != n)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_list_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_list_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

void	ft_list_clear(t_stack **lst)
{
	t_stack		*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
