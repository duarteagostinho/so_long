/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:42 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/28 17:36:04 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_cont;
	void	*n;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		n = f(lst->content);
		if (!n)
			ft_lstclear(&map, del);
		new_cont = ft_lstnew(n);
		if (!new_cont)
		{
			del(n);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_cont);
		lst = lst->next;
	}
	return (map);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
