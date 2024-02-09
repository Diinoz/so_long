/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicordie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:20:49 by nicordie          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:04 by nicordie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*newlst;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	newlst = 0;
	while (lst)
	{
		content = (*f)(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			del(content);
			return (0);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}
