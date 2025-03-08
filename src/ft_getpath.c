/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:53:29 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/07 17:59:01 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_free_vector(char **split)
// {
// 	int	i;
//
// 	i = 0;
// 	while (split[i])
// 		free(split[i++]);
// 	free(split);
// 	return (NULL);
// }

char	**ft_getpath(char *path)
{
	char	**path_list;
	char	*tmp;
	int		i;

	path_list = ft_split(path, ':');
	if (path_list == NULL)
		return (NULL);
	i = 0;
	while (path_list[i])
	{
		tmp = ft_strjoin(path_list[i], "/");
		if (tmp == NULL)
			return (ft_free_vector(path_list), ft_memlen);
		free(path_list[i]);
		path_list[i++] = tmp;
	}
	return (path_list);
}
