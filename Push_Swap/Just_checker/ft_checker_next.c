/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker.h"

// ---------------------------PROTOTYPE---------------------------
t_stack		*ft_init(int argc, char **argv);
t_stack		*ft_two_params(char **argv);
int			ft_duplicate(t_stack *a);
int			ft_issorted(t_stack *a);
int			ft_strcmp(const char *s1, const char *s2);
// ---------------------------------------------------------------

t_stack	*ft_init(int argc, char **argv)
{
	t_stack		*a;
	int			i;
	int			j;

	a = NULL;
	if (argc < 2)
		exit(6);
	if (argc == 2)
		a = ft_two_params(argv);
	else
	{
		i = 1;
		while (i < argc)
		{
			j = ft_atoi_strict(argv[i], &a, argv, 1);
			ft_list_add_back(&a, ft_list_new(j));
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

	i = 0;
	a = NULL;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		j = ft_atoi_strict(tmp[i], &a, tmp, 2);
		ft_list_add_back(&a, ft_list_new(j));
		i++;
	}
	ft_free_strs(tmp);
	free(tmp);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
