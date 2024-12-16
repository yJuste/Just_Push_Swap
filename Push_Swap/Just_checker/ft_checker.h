/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_CHECKER_H
# define FT_CHECKER_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// My library

# include "Get_Next_Line/get_next_line.h"

// Structure

typedef struct s_stack
{
	long				nbr;
	struct s_stack		*next;
}	t_stack;

// ft_checker.c

void		ft_checker(t_stack **a, t_stack **b);
void		ft_checker_next(t_stack **a, t_stack **b, char *line);
void		ft_checker_error(int err, t_stack **a, t_stack **b, char *line);

// ft_checker_next.c

t_stack		*ft_init(int argc, char **argv);
t_stack		*ft_two_params(char **argv);
int			ft_duplicate(t_stack *a);
int			ft_issorted(t_stack *a);
int			ft_strcmp(const char *s1, const char *s2);

// ft_instructions.c

void		ft_sa(t_stack **a, int flg);
void		ft_sb(t_stack **b, int flg);
void		ft_ss(t_stack **a, t_stack **b, int flg);
void		ft_pa(t_stack **a, t_stack **b, int flg);
void		ft_pb(t_stack **a, t_stack **b, int flg);

// ft_instructions_next.c

void		ft_ra(t_stack **a, int flg);
void		ft_rb(t_stack **b, int flg);
void		ft_rr(t_stack **a, t_stack **b, int flg);

// ft_instructions_next_2.c

void		ft_rra(t_stack **a, int flg);
void		ft_rrb(t_stack **b, int flg);
void		ft_rrr(t_stack **a, t_stack **b, int flg);

// ft_lib.c

int			ft_atoi_strict(const char *str, t_stack **a, char **argv, int flag);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_strs(char **lst);
void		ft_error(int err, t_stack **a, char **argv, int flag);
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

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
