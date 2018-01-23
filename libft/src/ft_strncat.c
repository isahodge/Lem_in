/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:56:08 by aderby            #+#    #+#             */
/*   Updated: 2017/06/07 10:58:51 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *ptr;

	ptr = s1;
	while (*ptr)
		ptr++;
	while (n > 0 && *s2 != '\0')
	{
		*ptr = *s2;
		n--;
		ptr++;
		s2++;
	}
	*ptr = '\0';
	return (s1);
}
