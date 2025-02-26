/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:05:58 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/01/14 14:07:47 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while ((ft_strchr(set, s1[start])) && s1[start])
		start++;
	while ((ft_strchr(set, s1[end])) && end > start)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
// #include <stdio.h>
// int main (void)
// {
//     // char s1[] = "a bcBonjourabc";
//     // char set[] = "bac q";
//     printf("<%s>\n", ft_strtrim("   xxx   xxx", " x"));
// }