/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:57:48 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/26 16:32:40 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

int	return_lenght(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += size_sep;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	len = return_lenght(size, strs, ft_strlen(sep));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i + 1 < size)
			res = ft_strcpy(res, sep);
	}
	*res = '\0';
	return (res - len);
}
/*
int main()
{
    char *strs[] = {"Hello", "world", "!"};
    char *sep = ", ";
    int size = 3;

    char *result = ft_strjoin(size, strs, sep);
    if (result)
    {
        printf("Result: %s\n", result);
        free(result);
    }

    return 0;
}*/
