/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 08:21:49 by maviot            #+#    #+#             */
/*   Updated: 2016/12/04 08:22:19 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_size;

	mem_size = (void *)malloc(size);
	if (mem_size == NULL)
		return (NULL);
	ft_memset(mem_size, 0, size);
	return (mem_size);
}
