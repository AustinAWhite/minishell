/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 23:19:54 by awhite            #+#    #+#             */
/*   Updated: 2019/01/19 23:29:17 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stacknode		*new_node(int data)
{
	t_stacknode *new_node;

	new_node = (t_stacknode *)malloc(sizeof(t_stacknode));
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int				stack_is_empty(t_stacknode *root)
{
	return (root == NULL ? 1 : 0);
}

void			stack_push(t_stacknode **root, int data)
{
	t_stacknode *node;

	node = new_node(data);
	node->next = *root;
	*root = node;
}

int				stack_pop(t_stacknode **root)
{
	t_stacknode *temp;

	if (stack_is_empty(*root))
		return (-1);
	temp = *root;
	*root = (*root)->next;
	free(*root);
	return (temp->data);
}

int				stack_peek(t_stacknode *root)
{
	if (stack_is_empty(root))
		return (-1);
	return (root->data);
}
