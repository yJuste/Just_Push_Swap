/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_next_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Movements : RRA RRB RRR                                       PART 3   */
/* ************************************************************************** */
#include "ft_pushswap.h"

// -----------------------PROTOTYPE-----------------------
void		ft_rra(t_stack **a, int flg);
void		ft_rrb(t_stack **b, int flg);
void		ft_rrr(t_stack **a, t_stack **b, int flg);
// -------------------------------------------------------

void	ft_rra(t_stack **a, int flg)
{
	int			i;
	t_stack		*tmp;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (flg == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int flg)
{
	int			i;
	t_stack		*tmp;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (flg == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int flg)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (flg == 0)
		write(1, "rrr\n", 4);
}
