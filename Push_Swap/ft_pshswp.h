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

int			main(int argc, char **argv);
t_stack		*ft_init(int argc, char **argv);
t_stack		*ft_two_params(char **argv);
int			ft_duplicate(t_stack *a);
int			ft_issorted(t_stack *a);

// ft_pshswp_2.c

void		ft_sort(t_stack **a);

// ft_instructions.c

void		ft_sa(t_stack **a, int flg);
void		ft_pb(t_stack **a, t_stack **b, int flg);
void		ft_ra(t_stack **a, int flg);
void		ft_rra(t_stack **a, int flg);

// ft_sort.c

void		ft_sort_three(t_stack **a);
int		ft_find_index(t_stack *a, int n);

// ft_lib.c

int			ft_list_size(t_stack *lst);
t_stack		*ft_list_new(int n);
t_stack		*ft_list_last(t_stack *lst);
void		ft_list_add_back(t_stack **lst, t_stack *new);
void		ft_list_add_front(t_stack **lst, t_stack *new);

// ft_lib_2.c

int			ft_list_min(t_stack *a);
int			ft_list_max(t_stack *a);
void		ft_list_clear(t_stack **lst);
void		ft_free_strs(char **lst);
void		ft_error(int err);

// ft_lib_3.c

int			ft_atoi_strict(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);

// ft_split.c

char		**ft_split(const char *s, char c);
size_t		ft_count_words(const char *s, char c);
char		**ft_split_next(char **out, const char *s, char c);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

#endif
