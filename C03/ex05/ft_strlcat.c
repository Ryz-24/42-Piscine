/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:24:42 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/16 13:27:26 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dl;
	unsigned int	sl;
	unsigned int	sum;

	i = 0;
	sum = 0;
	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	if (size > dl)
		sum = dl + sl;
	else
		sum = sl + size;
	while (src[i] && size > (dl + 1))
		dest[dl++] = src[i++];
	dest[dl] = '\0';
	return (sum);
}

int main() 
{
	char dest[10] = "ruba";
	char src[12] = " zaatreh";
	unsigned int size = 3;

	unsigned int result = ft_strlcat(dest, src, size);

	printf("Returned length: %u\n", result);
}
