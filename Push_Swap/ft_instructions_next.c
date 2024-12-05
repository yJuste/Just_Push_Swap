/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_next.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// ----------------------PROTOTYPE-----------------------
void		ft_ra(t_stack **a, int flg);
void		ft_rb(t_stack **b, int flg);
void		ft_rr(t_stack **a, t_stack **b, int flg);
// ------------------------------------------------------

void	ft_ra(t_stack **a, int flg)
{
	t_stack		*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_list_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (flg == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int flg)
{
	t_stack		*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (flg == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int flg)
{
	int		flg_2;

	flg_2 = 1;
	ft_ra(a, b, flg_2);
	ft_rb(a, b, flg_2);
	if (flg == 0)
		write(1, "rr\n", 3);
}
