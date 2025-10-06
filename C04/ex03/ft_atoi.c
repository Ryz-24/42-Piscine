/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:58 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/22 14:25:24 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	count;
	int	num;

	count = 0;
	num = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				count++;
			str++;
		}
		while (*str >= 48 && *str <= 57)
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
		if (count % 2 != 0)
			return (num * -1);
		return (num);
	}
	return (0);
}
/*
int main(int arc, char **argv)
{
	char	*a =  " ---+--+1234ab567";
	printf("%d\n", ft_atoi(a));
}*/
