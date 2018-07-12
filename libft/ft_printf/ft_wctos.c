/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconti <mconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:06:12 by mconti            #+#    #+#             */
/*   Updated: 2018/06/19 20:18:15 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_wctos(wchar_t c, char *dest)
{
	ft_bzero(dest, 5);
	if (c <= 128)
		dest[0] = c;
	else if (c <= 2048)
	{
		dest[0] = ((c >> 6) & 31) | 192;
		dest[1] = (c & 63) | 128;
		return (2);
	}
	else if (c <= 65536)
	{
		dest[0] = ((c >> 12) & 15) | 224;
		dest[1] = ((c >> 6) & 63) | 128;
		dest[2] = (c & 63) | 128;
		return (3);
	}
	else
	{
		dest[0] = ((c >> 18) & 7) | 240;
		dest[1] = ((c >> 12) & 63) | 128;
		dest[2] = ((c >> 6) & 63) | 128;
		dest[3] = (c & 63) | 128;
		return (4);
	}
	return (1);
}
