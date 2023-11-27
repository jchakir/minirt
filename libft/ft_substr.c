/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:41:49 by hbourkan          #+#    #+#             */
/*   Updated: 2022/05/16 18:58:51 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		return (ft_strdup((char *)s + start));
	return (ft_strndup(s + start, len));
}
