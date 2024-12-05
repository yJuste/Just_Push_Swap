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
/*   • Sort a pile A with another pile B.                                     */
/*   • ./a.out [ numbers ]                                                    */
/*      -> numbers    [ int ]                                                 */
/* ************************************************************************** */
#ifndef FT_PSHSWP_H
# define FT_PSHSWP_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// My library

# include "Printf/ft_printf.h"

// Structures

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flag
{
	char		a;
	char		b;
}	t_flag;

//	---------- MY CODE ----------

// ft_pshswp.c

int			main(int argc, char **argv);
t_stack		*ft_init(int argc, char **argv);
t_stack		*ft_two_params(char **argv);
int			ft_duplicate(t_stack *a);
int			ft_issorted(t_stack *a);

// ft_pshswp_2.c

void		ft_sort(t_stack **a);
void		ft_sort_three(t_stack **a);
int			ft_parse(t_stack *a, t_stack *b, char s);

// ft_pshswp_3.c

t_stack		*ft_sort_b(t_flag *flag, t_stack **a);
t_stack		**ft_sort_a(t_flag *flag, t_stack **a, t_stack **b);
void		ft_sort_b_next(t_flag *flag, t_stack **a, t_stack **b);
int			ft_find_place_b(t_stack *b, int n);
int			ft_find_place_a(t_stack *a, int n);

// ft_apply.c

int			ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);

// ft_is.c

int			ft_is_rarb(t_stack *a, t_stack *b, int c, char s);
int			ft_is_rrarrb(t_stack *a, t_stack *b, int c, char s);
int			ft_is_rrarb(t_stack *a, t_stack *b, int c, char s);
int			ft_is_rarrb(t_stack *a, t_stack *b, int c, char s);

// ft_instructions.c

void		ft_sa(t_stack **a, int flg);
void		ft_sb(t_stack **b, int flg);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
void		ft_ra(t_stack **a, int flg);
void		ft_rb(t_stack **b, int flg);

// ft_instructions_next.c

void		ft_rr(t_stack **a, t_stack **b);
void		ft_rra(t_stack **a, int flg);
void		ft_rrb(t_stack **b, int flg);
void		ft_rrr(t_stack **a, t_stack **b);

// ft_lib.c

int			ft_atoi_strict(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_strs(char **lst);
void		ft_error(int err);
int			ft_isdigit(int c);

// ft_list_lib.c

t_stack		*ft_list_new(int n);
void		ft_list_add_back(t_stack **lst, t_stack *new);
void		ft_list_add_front(t_stack **lst, t_stack *new);
int			ft_list_size(t_stack *lst);
t_stack		*ft_list_last(t_stack *lst);

// ft_list_lib_2.c

int			ft_find_index(t_stack *a, int n);
int			ft_list_min(t_stack *a);
int			ft_list_max(t_stack *a);
void		ft_list_clear(t_stack **lst);

// ft_split.c

char		**ft_split(const char *s, char c);
size_t		ft_count_words(const char *s, char c);
char		**ft_split_next(char **out, const char *s, char c);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

#endif
