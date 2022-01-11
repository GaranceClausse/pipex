/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:24:59 by gclausse          #+#    #+#             */
/*   Updated: 2021/11/30 19:24:29 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	void	*tmp;
	t_list	*ret;

	if (lst && f)
	{
		ret = NULL;
		while (lst)
		{
			tmp = f(lst->content);
			map = ft_lstnew(tmp);
			if (map == NULL)
				ft_lstclear(&ret, del);
			ft_lstadd_back(&ret, map);
			lst = lst->next;
		}
		return (ret);
	}
	return (NULL);
}
