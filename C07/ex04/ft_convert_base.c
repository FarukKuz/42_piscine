/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:28:39 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/12 20:41:55 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	base_len(char *base);
int	base_check(char *base);

void	swap_chars(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse_str(char **str)
{
	int		i;
	int		j;
	char	*s;

	s = *str;
	i = 0;
	j = 0;
	while (s[j])
		j++;
	j--;
	while (i < j)
	{
		if (s[i] == '-')
			i++;
		swap_chars(&s[i], &s[j]);
		i++;
		j--;
	}
}

int	count_digit(char *base, int value)
{
	int	len;
	int	counter;

	counter = 0;
	if (value < 0)
		counter++;
	len = base_len(base);
	if (value < 0)
		value *= -1;
	while (value >= len)
	{
		value /= len;
		counter++;
	}
	counter += 1;
	return (counter);
}

void	fill_dest_with_number(int num, char *base_to, int len, char *dest)
{
	int	i;

	i = 0;
	dest[i] = 0;
	if (num < 0)
	{
		dest[i] = '-';
		i++;
		num = -num;
	}
	while (num >= len)
	{
		dest[i] = base_to[num % len];
		num /= len;
		i++;
	}
	dest[i] = base_to[num];
	dest[i + 1] = 0;
	reverse_str(&dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*dest;
	int		size;
	int		i;
	int		len;

	if (!base_check(base_to) || !base_check(base_from))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	size = count_digit(base_to, num);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	i = 0;
	len = base_len(base_to);
	fill_dest_with_number(num, base_to, len, dest);
	return (dest);
}

