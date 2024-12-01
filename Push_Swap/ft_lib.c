/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// -------------------------PROTOTYPE-------------------------
t_stack	*ft_lstnew_pushswap(int content);
t_stack	*ft_lstlast_pushswap(t_stack *lst);
void	ft_lstclear_pushswap(t_stack **lst);
void	ft_lstadd_back_pushswap(t_stack **lst, t_stack *new);
void	ft_lstadd_front_pushswap(t_stack **lst, t_stack *new);
// -----------------------------------------------------------

t_stack	*ft_lstnew_pushswap(int nbr)
{
	t_stack		*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		ft_error(-4);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

t_stack	*ft_lstlast_pushswap(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_pushswap(t_stack **lst)
{
	t_stack		*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_back_pushswap(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
		ft_lstadd_front_pushswap(lst, new);
	else
		(ft_lstlast_pushswap(*lst))->next = new;
}

void	ft_lstadd_front_pushswap(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
