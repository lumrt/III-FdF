/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:46:26 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/21 17:37:28 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	remmtab;

	if (s == NULL)
		return (NULL);
	remmtab = ft_strlen(s) - start;
	if (start < (unsigned int)ft_strlen(s))
	{
		if (remmtab > len)
			tab = (char *)ft_calloc(sizeof(char), len + 1);
		else
			tab = (char *)ft_calloc(sizeof(char), remmtab + 1);
		if (tab == NULL)
			return (NULL);
		ft_strlcpy(tab, &s[start], len + 1);
	}
	else
		tab = (char *)ft_calloc(1, 1);
	return (tab);
}
