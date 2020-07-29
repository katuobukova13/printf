/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:56:33 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 03:58:52 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *curr;

	if (lst != NULL && del != NULL)
	{
		while ((*lst) != NULL)
		{
			curr = (*lst)->next;
			del(((*lst)->content));
			free(*lst);
			*lst = curr;
		}
	}
}
