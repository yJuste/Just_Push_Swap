/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pshswp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PSHSWP_H
# define FT_PSHSWP_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// My library

# include "Printf/ft_printf.h"

// Structure

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//	---------- MY CODE ----------

// ft_pshswp.c

int		main(int argc, char **argv);

// ft_lib.c

t_stack	*ft_list_new(int n);
t_stack	*ft_list_last(t_stack *lst);
void	ft_list_clear(t_stack **lst);
void	ft_list_add_back(t_stack **lst, t_stack *new);
void	ft_list_add_front(t_stack **lst, t_stack *new);

// ft_lib2.c

int		ft_list_size(t_stack *lst);

#endif

