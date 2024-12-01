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

// ---------------------PROTOTYPE----------------------
t_stack	*ft_list_new(int n);
t_stack	*ft_list_last(t_stack *lst);
void	ft_list_clear(t_stack **lst);
void	ft_list_add_back(t_stack **lst, t_stack *new);
void	ft_list_add_front(t_stack **lst, t_stack *new);
// ----------------------------------------------------

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

t_stack	*ft_list_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
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

void	ft_list_add_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		ft_lstadd_front_pushswap(lst, new);
	else
		(ft_list_last(*lst))->next = new;
}

void	ft_list_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
