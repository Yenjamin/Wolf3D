/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:28:26 by yechen            #+#    #+#             */
/*   Updated: 2017/06/21 15:14:38 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char const *s)
{
	int	word;
	int	index;

	if (*s == '\0')
		return (0);
	index = 0;
	if (s[index] != ' ')
		word = 1;
	else
		word = 0;
	index++;
	while (s[index])
	{
		if (s[index - 1] == ' ' && s[index] != ' ')
			word++;
		index++;
	}
	return (word);
}