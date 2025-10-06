/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:14:52 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/23 13:16:02 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		size;

	size = 0;
	while (src[size])
		size++;
	(s = (char *)malloc(sizeof(char) * (size + 1)));
	if (!s)
		return (0);
	s[size] = '\0';
	while (size > 0)
	{
		size--;
		s[size] = src[size];
	}
	return (s);
}
/*
int	main(void)
{
	char *a = "hello world";
	char *b = ft_strdup(a);
	if(b)
	{
		printf("%s\n", a);
		printf("%s\n", b);
		free(b);
	}
	else
		printf("memory allocation failed");
}*/
