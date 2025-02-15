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
/*   • First Lib                                                              */
/* ************************************************************************** */
#include "ft_pushswap.h"

// ----------------------------------PROTOTYPE----------------------------------
int			ft_atoi_strict(const char *str, t_stack **a, char **argv, int flag);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_strs(char **lst);
void		ft_error(int err, t_stack **a, char **argv, int flag);
int			ft_isdigit(int c);
// -----------------------------------------------------------------------------

int	ft_atoi_strict(const char *str, t_stack **a, char **argv, int flag)
{
	int					sign;
	long long int		res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error(2, a, argv, flag);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(2, a, argv, flag);
		res = res * 10 + *str - '0';
		str++;
	}
	if ((sign * res) > 2147483647
		|| (sign * res) < -2147483648)
		ft_error(3, a, argv, flag);
	return (sign * res);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total_size;
	void		*ptr;

	i = 0;
	if (count == 0 || size == 0)
		total_size = 0;
	else
		total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void	ft_free_strs(char **str)
{
	char		*i;

	if (!str)
		return ;
	while (*str)
	{
		i = *str;
		free(i);
		str++;
	}
	*str = NULL;
}

void	ft_error(int err, t_stack **a, char **argv, int flag)
{
	if (flag == 2 && argv)
	{
		ft_free_strs(argv);
		free(argv);
	}
	if (*a)
		ft_list_clear(a);
	write(2, "Error\n", 6);
	exit(err);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
