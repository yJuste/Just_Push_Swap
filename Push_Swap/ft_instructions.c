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

// -----------------PROTOTYPE-------------------
void		ft_sa(t_stack **a, int flg);
void		ft_sb(t_stack **b, int flg);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_ra(t_stack **a, int flg);
void		ft_rb(t_stack **b, int flg);
// ---------------------------------------------

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

/*	|--------- NEVER USED ---------|
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
 }	|------------------------------|*/
/*	|--------- NEVER USED ---------|
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	write(1, "ss\n", 3);
}	|------------------------------|*/

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	write(1, "pb\n", 3);
}

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
	*b = ft_list_last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (flg == 0)
		write(1, "rb\n", 3);
}
