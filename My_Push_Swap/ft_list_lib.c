/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • First lib for chained list.                                            */
/* ************************************************************************** */
#include "ft_pushswap.h"

// -------------------------PROTOTYPE--------------------------
t_stack		*ft_list_new(int n);
void		ft_list_add_back(t_stack **lst, t_stack *new);
void		ft_list_add_front(t_stack **lst, t_stack *new);
int			ft_list_size(t_stack *lst);
t_stack		*ft_list_last(t_stack *lst);
// ------------------------------------------------------------

t_stack	*ft_list_new(int n)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ft_list_add_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		ft_list_add_front(lst, new);
	else
		(ft_list_last(*lst))->next = new;
}

void	ft_list_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_list_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_list_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
