/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:31:49 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/16 09:47:09 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
    char dest[100] = "Hello, ";
    char src[] = "World!";

    printf("Before: %s\n", dest);
    ft_strcat(dest, src);
    printf("After: %s\n", dest);

    return 0;
}*/
