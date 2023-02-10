/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:55:38 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 03:14:03 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



static	int	check(const char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\v' || \
		ch == '\r' || ch == '\n' || ch == '\f')
		return (1);
	return (0);
}

static char	*skip_whitespaces(const char *str)
{
	char	*substring;

	substring = (char *)str;
	while (check(*substring) == 1)
		substring++;
	return (substring);
}

static int	get_sign(char *substring, char **updated_substring)
{
	int	sign;

	sign = 1;
	if (*substring == '-')
	{
		substring++;
		sign *= -1;
	}
	else if (*substring == '+')
		substring++;
	*updated_substring = substring;
	return (sign);
}

static int	convert_to_int(char *substring, int sign)
{
	int	decimal_val;
	int	result;

	decimal_val = 0;
	result = 0;
	while ((*substring >= '0' && *substring <= '9') && *substring != '\0')
	{
		decimal_val = *substring - '0';
		result = result * 10 + decimal_val;
		substring++;
	}
	return (result * sign);
}

/** ft_atoi refactored to make things easy
 *  read from bottom to up **/
int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	char	*substring;

	substring = skip_whitespace(str);
	sign = get_sign(substring, &substring);
	result = convert_to_int(substring, sign);
	return (result);
}
