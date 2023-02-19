/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:53:07 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 15:13:16 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		ft_free_ptr((void *)&matrix[i]);
		i++;
	}
	ft_free_ptr((void *)&matrix);
}

int	ft_chrpos(char *s, int c)
{
	int				i;
	unsigned char	*temp;
	unsigned char	temp_c;

	i = 0;
	temp = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (temp[i] != '\0')
	{
		if (temp[i] == temp_c)
			return (i);
		i++;
	}
	if (temp_c == '\0')
		return (-1);
	return (-1);
}

static void	conc_str(char **result, char *str)
{
	char	*temp;
	char	*aux;

	temp = ft_strjoin(" ", str);
	aux = ft_strjoin(*result, temp);
	free(*result);
	*result = ft_strdup(aux);
	free(temp);
	free(aux);
}

char	*ft_matrix_to_str(char **matrix)
{
	int		i;
	char	*temp;
	char	*result;

	if (!matrix)
		return (ft_strdup(""));
	i = 0;
	while (matrix[i])
	{
		if (i == 0)
			result = ft_strdup(matrix[i]);
		else
			conc_str(&result, matrix[i]);
		i++;
	}
	temp = ft_strjoin(result, "");
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}

char	**ft_lst_to_matrix(t_list *lst)
{
	int		i;
	char	**matrix;

	if (lst == NULL)
		return (NULL);
	i = ft_lstsize(lst);
	matrix = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (lst)
	{
		matrix[i] = ft_strdup((char *)lst->content);
		lst = lst->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	ft_chrqty(char *s, int c)
{
	int				i;
	int				qtd;
	unsigned char	*temp;
	unsigned char	temp_c;

	i = 0;
	qtd = 0;
	temp = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (temp[i] != '\0')
	{
		if (temp[i] == temp_c)
			qtd++;
		i++;
	}
	return (qtd);
}
