/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:28:15 by sebang            #+#    #+#             */
/*   Updated: 2023/02/01 17:30:09 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_create_elem(void *data);

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	return (node);
}
