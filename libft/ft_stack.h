/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 23:22:53 by awhite            #+#    #+#             */
/*   Updated: 2019/01/19 23:29:34 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdlib.h>

typedef struct			s_stacknode {
	int					data;
	struct s_stacknode	*next;
}						t_stacknode;

t_stacknode				*new_node(int data);
int						stack_is_empty(t_stacknode *root);
void					stack_push(t_stacknode **root, int data);
int						stack_pop(t_stacknode **root);
int						stack_peek(t_stacknode *root);

#endif
