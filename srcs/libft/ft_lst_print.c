/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:04:59 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *head)
{
	int		count;
	t_list	*tmp;
	char	*num;

	if (!head)
		return ;
	count = 0;
	tmp = head;
	while (tmp)
	{
		num = ft_itoa(count);
		write(1, num, ft_strlen(num));
		write(1, ": ", 2);
		write(1, tmp->content, ft_strlen(tmp->content));
		ft_putchar('\n');
		free(num);
		count++;
		tmp = tmp->next;
	}
}
