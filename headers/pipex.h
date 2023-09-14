/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:11:08 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/09/14 04:39:08 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

int		open_file(char *file, int read_write);
void	free_tab(char **tab);
char	*ft_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	run_cmds(char *cmd, char **env);

#endif