/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:50:16 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/09/12 17:21:16 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	open_file(char *file, int read_write)
{
	int	ret;

	ret = -1;
	if (read_write == 0)
		ret = open(file, O_RDONLY, 0777);
	if (read_write == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(1);
	return (ret);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		str = ft_substr(env[i], 0, j);
		if (ft_strcmp(str, name) == 0)
		{
			free(str);
			return (env[i] + j + 1);
		}
		free(str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**path_list;
	char	*path;
	char	**cmd_list;

	i = -1;
	path_list = ft_split(ft_getenv("PATH", env), ':');
	cmd_list = ft_split(cmd, ' ');
	while (path_list[++i])
	{
		path = ft_strjoin(path_list[i], "/");
		exec = ft_strjoin(path, cmd_list[0]);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_tab(cmd_list);
			return (exec);
		}
		free(exec);
	}
	free_tab(path_list);
	free_tab(cmd_list);
	return (cmd);
}

void	run_cmds(char *cmd, char **env)
{
	char	**cmd_list;
	char	*path;

	cmd_list = ft_split(cmd, ' ');
	path = get_path(cmd_list[0], env);
	if (execve(path, cmd_list, env) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd_list[0], 2);
		free_tab(cmd_list);
		exit(127);
	}
}
