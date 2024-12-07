/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:46:11 by hrasolom          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:41 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	long long int	value;
	int				indice;
	struct t_list	*target;
	struct t_list	*next;

}					t_list;

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				sa(t_list **a);
void				sb(t_list **b);
void				pb(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				ss(t_list **b, t_list **a);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
char				**ft_split(char *s, char c);
long long int		ft_atoi(char *nptr);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(char c);
void				free_stack(t_list *stack);
void				free_split(char **split);
void				sort_three(t_list **stack);
t_list				*find_max(t_list **stack);
int					stack_size(t_list *stack);
void				write_error(void);
void				push_a_to_b(t_list **a, t_list **b);
void				init(t_list *list);
t_list				*find_min(t_list **stack);
void				move(t_list **a);
void				target_search(t_list **a, t_list **b);
void				find_target(t_list **a, t_list *b, t_list **max);
int					count(t_list *stack, int size);
void				move_element_to_top(t_list **stack, t_list *instructions);
void				move_element_to_top_b(t_list **stack, t_list *instructions);
void				init_stack(t_list **a, t_list **b, char **argv);
void				check_double(t_list **stack);
void				check_error(char *argv);
void				ft_free(t_list **stack);
char				*ft_strnstr(char *big, char *little, size_t len);
void				free_stack(t_list *stack);

#endif
