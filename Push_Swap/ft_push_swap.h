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

// ft_push_swap.c

int		main(int argc, char **argv);
int		ft_duplicate(t_stack *a);
int		ft_issorted(t_stack *a);
t_stack	*ft_init(int argc, char **argv);
t_stack	*ft_two_params(char **argv);

// ft_push_swap_lib.c

t_stack	*ft_lstnew_pushswap(int content);
t_stack	*ft_lstlast_pushswap(t_stack *lst);
void	ft_lstclear_pushswap(t_stack **lst);
void	ft_lstadd_back_pushswap(t_stack **lst, t_stack *new);
void	ft_lstadd_front_pushswap(t_stack **lst, t_stack *new);

#endif

