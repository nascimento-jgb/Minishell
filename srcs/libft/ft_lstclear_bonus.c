/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:13:57 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/20 16:04:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}
