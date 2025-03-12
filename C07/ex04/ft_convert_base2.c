/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:38:24 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/12 13:40:13 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (0);
	if (base_len(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_with_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (i);
}

int	check(char *base, char *str, int i)
{
	int	a;
	int	index;
	int	result;
	int	bas;

	bas = base_len(base);
	result = 0;
	while (str[i])
	{
		a = 0;
		while (base[a] != str[i])
			a++;
		if (str[i] == base[a] && a < bas)
		{
			index = count_with_index(base, str[i]);
			result = result * bas + index;
		}
		else
		{
			return (result);
		}
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (!base_check(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = check(base, str, i);
	return (result * sign);
}
