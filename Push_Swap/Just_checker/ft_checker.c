/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_checker.h"

// ----------------------------------PROTOTYPE----------------------------------
void		ft_checker(t_stack **a, t_stack **b);
void		ft_checker_next(t_stack **a, t_stack **b, char *line);
void		ft_checker_error(int err, t_stack **a, t_stack **b, char *line);
// -----------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	a = ft_init(argc, argv);
	if (!a || ft_duplicate(a))
		ft_error(4, &a, argv, 0);
	ft_checker(&a, &b);
	ft_list_clear(&b);
	ft_list_clear(&a);
	return (0);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char		*line;

	line = get_next_line(0);
	if (!line && ft_issorted(*a))
		return (write(1, "OK\n", 3), ft_checker_error(8, a, b, line));
	if (!line && !ft_issorted(*a))
		return (write(1, "KO\n", 3), ft_checker_error(9, a, b, line));
	while (line && *line != '\n')
	{
		ft_checker_next(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_issorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return ;
}

void	ft_checker_next(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(a, b, 1);
	else
		ft_checker_error(7, a, b, line);
}

void	ft_checker_error(int err, t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	if (*a)
		ft_list_clear(a);
	if (*b)
		ft_list_clear(b);
	if (err == 8 || err == 9)
		exit(err);
	write(2, "Error\n", 6);
	exit(err);
}
