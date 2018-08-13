/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:44:47 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 12:18:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		strptoi(char **strp)
{
	int		n;
	int		sign;
	char	*s;

	s = *strp;
	while (*s <= ' ')
		s++;
	sign = *s == '-' ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	n = 0;
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *s++ - '0';
	*strp = s;
	return (n * sign);
}
