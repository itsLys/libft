/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execvpe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:54:13 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/07 17:59:01 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_vector(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

void	execute_file(char **path_list, char *file, char **av, char **envp)
{
	char	*file_path;
	int		i;

	i = 0;
	while (path_list[i])
	{
		file_path = ft_strjoin(path_list[i++], file);
		if (file_path == NULL)
			return ;
		execve(file_path, av, envp);
		free(file_path);
	}
	perror(file);
}

int	ft_execvpe(char *file, char **av, char **envp)
{
	char	*path;
	char	**path_list;

	if (ft_strchr(file, '/') && execve(file, av, envp) == ERROR)
		return (ERROR);
	path = ft_getenv(envp, "PATH=");
	if (path == NULL)
		return (ERROR);
	path_list = ft_getpath(path);
	if (path_list == NULL)
		return (ERROR);
	execute_file(path_list, file, av, envp);
	ft_free_vector(path_list);
	return (ERROR);
}
