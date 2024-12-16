/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pshswp_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Algorithm that sort B and A.                                           */
/* ************************************************************************** */
#include "ft_pshswp.h"

// ----------------------------PROTOTYPE-------------------------------
t_stack		*ft_sort_b(t_flag *flag, t_stack **a);
t_stack		**ft_sort_a(t_flag *flag, t_stack **a, t_stack **b);
void		ft_sort_b_next(t_flag *flag, t_stack **a, t_stack **b);
int			ft_find_place_b(t_stack *b, int n);
int			ft_find_place_a(t_stack *a, int n);
// --------------------------------------------------------------------

//	---------- PART B ----------

t_stack	*ft_sort_b(t_flag *flg, t_stack **a)
{
	t_stack		*b;

	b = NULL;
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_pb(a, &b, 0);
	if (ft_list_size(*a) > 3 && !ft_issorted(*a))
		ft_sort_b_next(flg, a, &b);
	if (!ft_issorted(*a))
		ft_sort_three(a);
	return (b);
}

void	ft_sort_b_next(t_flag *flg, t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*tmp;

	while (ft_list_size(*a) > 3 && !ft_issorted(*a))
	{
		tmp = *a;
		i = ft_parse(*a, *b, flg->b);
		while (i >= 0)
		{
			if (i == ft_is_rr(*a, *b, tmp->nbr, flg->b))
				i = ft_push_rr(a, b, tmp->nbr, flg->b);
			else if (i == ft_is_rrr(*a, *b, tmp->nbr, flg->b))
				i = ft_push_rrr(a, b, tmp->nbr, flg->b);
			else if (i == ft_is_rarrb(*a, *b, tmp->nbr, flg->b))
				i = ft_push_rarrb(a, b, tmp->nbr, flg->b);
			else if (i == ft_is_rrarb(*a, *b, tmp->nbr, flg->b))
				i = ft_push_rrarb(a, b, tmp->nbr, flg->b);
			else
				tmp = tmp->next;
		}
	}
}

int	ft_find_place_b(t_stack *b, int n)
{
	int			i;
	t_stack		*tmp;

	i = 1;
	if (n > b->nbr && n < ft_list_last(b)->nbr)
		i = 0;
	else if (n > ft_list_max(b) || n < ft_list_min(b))
		i = ft_find_index(b, ft_list_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < n || tmp->nbr > n)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

//	---------- PART A ----------

t_stack	**ft_sort_a(t_flag *flg, t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*tmp;

	while (*b)
	{
		tmp = *b;
		i = ft_parse(*a, *b, flg->a);
		while (i >= 0)
		{
			if (i == ft_is_rr(*a, *b, tmp->nbr, flg->a))
				i = ft_push_rr(a, b, tmp->nbr, flg->a);
			else if (i == ft_is_rrr(*a, *b, tmp->nbr, flg->a))
				i = ft_push_rrr(a, b, tmp->nbr, flg->a);
			else if (i == ft_is_rarrb(*a, *b, tmp->nbr, flg->a))
				i = ft_push_rarrb(a, b, tmp->nbr, flg->a);
			else if (i == ft_is_rrarb(*a, *b, tmp->nbr, flg->a))
				i = ft_push_rrarb(a, b, tmp->nbr, flg->a);
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

int	ft_find_place_a(t_stack *a, int n)
{
	int			i;
	t_stack		*tmp;

	i = 1;
	if (n < a->nbr && n > ft_list_last(a)->nbr)
		i = 0;
	else if (n > ft_list_max(a) || n < ft_list_min(a))
		i = ft_find_index(a, ft_list_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > n || tmp->nbr < n)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
