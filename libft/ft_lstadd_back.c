/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:52:45 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 03:05:24 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *curr;

	if (*lst == NULL)
		*lst = new;
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	curr->next->next = NULL;
	return ;
}
