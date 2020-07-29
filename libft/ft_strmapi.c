/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:44:33 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 04:17:46 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*news;
	char			*ss;
	unsigned int	len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	ss = (char *)s;
	i = 0;
	len = ft_strlen(ss);
	news = (char *)malloc(sizeof(char) * (len + 1));
	if (news == NULL)
		return (NULL);
	while (ss[i] != '\0')
	{
		news[i] = f(i, ss[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}
