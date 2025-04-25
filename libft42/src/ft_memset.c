/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:02:51 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/04/25 15:30:37 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*bcopy;

	bcopy = b;
	i = 0;
	while (i < len)
	{
		bcopy[i] = c;
		i++;
	}
	bcopy[i] = '\0';
	return (b);
}
/*
int	main(void)
{
	int c = 114;
	char b[] = "bonj1234";
	printf("la mienne : %s\n", ft_memset(b, c, 4));
	printf("l'original : %s\n", memset(b, c, 4));
}*/
