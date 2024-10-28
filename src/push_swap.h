/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:00:12 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/28 12:12:41 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../My_Libft/src/my_libft.h"
# include <stdbool.h>
# include <limits.h>

# define unsigned int BOOL;

# define TRUE 1
# define FALSE 0
# define ABOVE 1
# define UNDER 0

# ifndef CW
#  define CW 0
# endif

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*target;
	int				median;
	int				price;
	int				best_move;
	int				targ_index;
	struct s_stack	*next;
}			t_stack;

// List generation and input checking
bool	check_double(t_stack **lst);
int		convert_to_int(char *tab_split);
char	**fill_tab(int count, char **input);
void	ft_fill_list(char **tab_split, t_stack **lst);
void	ft_lstclear_push(t_stack **list, void (*del)(int));
void	ft_lstadd_back_push(t_stack **lst, t_stack *new);
t_stack	*ft_newlst(t_stack **list, int content);
void	free_all_lst(char **s);
bool	check_input(char *str);
bool	ft_check_if_sorted(char **tab_split);
bool	ft_check_if_sorted_list(t_stack *list);
bool	ft_check_split_tab(char **tab_split);
bool	check_digits(char *str);
bool	is_num(char c);
bool	check_signs(char *str);
bool	check_length(char *str);
bool	check_spaces(char *str);
void	del(int content);
void	ft_lstadd_front_push(t_stack **lst, t_stack *new);
long	ft_atol(const char *s);
void	initiate_struc_b(t_stack *listA, t_stack *listB);
void	initiate_struc_a(t_stack *listA);
int		find_target(int nbr, t_stack *listA);
void	set_target_b(t_stack *listA, t_stack *listB);

// Operations
void	push_a(t_stack **listA, t_stack **listB);
void	push_b(t_stack **listA, t_stack **listB);
void	rotate_a(t_stack **listA, int nb);
void	rotate_b(t_stack **listB, int nb);
void	rotate_rr(t_stack **listA, t_stack **listB);
void	reverse_rotate_rra(t_stack **listA, int nb);
void	reverse_rotate_rrb(t_stack **listB, int nb);
void	reverse_rotate_rrr(t_stack **listA, t_stack **listB);
void	swap_a(t_stack **listA, int nb);
void	swap_b(t_stack **listB, int nb);
void	swap_ss(t_stack **listA, t_stack **listB);
int		ft_lstsize_push(t_stack *lst);
void	norm_swap_rra(t_stack **list);
void	norm_swap_ra(t_stack **list);

// Algorythm
int		find_position(int nbr, t_stack *list);
int		find_min_content(t_stack *list);
int		find_min(t_stack *list);
int		find_max(t_stack *list);
int		best_move_btoa(int size, t_stack *listA, t_stack *listB);
t_stack	**ft_initiate_list_b(t_stack **listA, t_stack **listB);
void	solve_stack_3(t_stack **listA);
t_stack	*solve_stack_b(t_stack **listA, t_stack **listB);
t_stack	**sort_stack_a(t_stack **listA, t_stack **listB);

//Median handling
int		calculate_median(t_stack *list);
bool	own_median(int index, t_stack *list);
t_stack	*ft_lstlast_push(t_stack *lst);

// Rotation count
int		case_ab_ab(int size, t_stack *listA, t_stack *listB);
int		case_ab_un(t_stack *listA, t_stack *listB);
int		case_un_ab(int size, t_stack *listB);
int		case_un_un(t_stack *listA, t_stack *listB);

// Execution
void	execute_rra_rrb(int content, t_stack **listA, t_stack **listB);
void	execute_ra_rb(int content, t_stack **listA, t_stack **listB);
void	execute_ra_rrb(int content, t_stack **listA, t_stack **listB);
void	execute_rra_rb(int content, t_stack **listA, t_stack **listB);
void	execute_solve_5(int ac, t_stack **listA, t_stack **listB);
void	final_twist_a(t_stack	**listA);
void	ft_print_list(t_stack *list);

#endif