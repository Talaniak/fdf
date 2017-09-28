/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 07:23:34 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 02:40:17 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lst_next;

	lst = *alst;
	while (lst)
	{
		lst_next = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst_next;
	}
	*alst = NULL;
}
