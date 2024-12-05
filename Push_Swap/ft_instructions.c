/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// ----------------------PROTOTYPE-----------------------
void		ft_sa(t_stack **a, int flg);
void		ft_sb(t_stack **b, int flg);
void		ft_ss(t_stack **a, t_stack **b, int flg);
void		ft_pa(t_stack **a, t_stack **b, int flg);
void		ft_pb(t_stack **a, t_stack **b, int flg);
// ------------------------------------------------------

void	ft_sa(t_stack **a, int flg)
{
	t_stack		*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (flg == 0)
		write(1, "sa\n", 3);
	return ;
}

void	ft_sb(t_stack **b, int flg)
{
	t_stack		*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (flg == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int flg)
{
	int		flg_2;

	flg_2 = 1;
	ft_sa(a, flg_2);
	ft_sb(b, flg_2);
	if (flg == 0)
		write(1, "ss\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int flg)
{
	t_stack		*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (flg == 0)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int flg)
{
	t_stack		*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (flg == 0)
		write(1, "pb\n", 3);
}
