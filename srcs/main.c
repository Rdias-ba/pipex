/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:10:22 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/09/12 17:13:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child(char **argv, int *folders, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(folders[1], 1);
	close(folders[0]);
	run_cmds(argv[2], env);
}

void	parent(char **argv, int *folders, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(folders[0], 0);
	close(folders[1]);
	run_cmds(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		folders[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("ERROR: ./pipex infile cmd cmd outfile\n", 2);
		exit(1);
	}
	if (pipe(folders) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(argv, folders, env);
	parent(argv, folders, env);
}
