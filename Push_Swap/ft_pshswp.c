/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pshswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_pshswp.h"

// ----------------PROTOTYPE----------------
int		main(int argc, char **argv);
t_stack	*ft_init(int argc, char **argv);
t_stack	*ft_two_params(char **argv);
int		ft_duplicate(t_stack *a);
int		ft_issorted(t_stack *a);
// -----------------------------------------

int	main(int argc, char **argv)
{
	t_stack		*a;

	a = ft_init(argc, argv);
	if (!a || ft_duplicate(a))
	{
		ft_lstclear_pushswap(&a);
		ft_error(-2);
	}
	if (!ft_issorted(a))
		ft_sort(&a);
	ft_lstclear_pushswap(&a);
	return (0);
}

/*
t_stack	*ft_init(int argc, char **argv)
{
	t_stack		*a;
	int			i;
	int			j;

	a = NULL;
	if (argc < 2)
		ft_error(-1);
	if (argc == 2)
		a = ft_two_params(argv);
	else
	{
		i = 1;
		while (i < argc)
		{
			j = ft_atoi_strict(argv[i]);
			ft_lstadd_back_pushswap(&a, ft_lstnew_pushswap(j));
			i++;
		}
	}
	return (a);
}

t_stack	*ft_two_params(char **argv)
{
	t_stack		*a;
	char		**tmp;
	int			i;
	int			j;

	a = NULL;
	tmp = ft_split(argv[1], ' ');
	i = 0;
	while (tmp[i])
	{
		j = ft_atoi_strict(tmp[i]);
		ft_lstadd_back_pushswap(&a, ft_lstnew_pushswap(j));
		i++;
	}
	ft_free_str_2(tmp);
	return (a);
}

int	ft_duplicate(t_stack *a)
{
	t_stack		*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_issorted(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}
*/
