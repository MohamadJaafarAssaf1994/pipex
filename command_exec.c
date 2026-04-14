/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:00 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/11 15:05:54 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_command_data(t_comargs *cmd, char **path_env_tab)
{
	if (cmd->command && cmd->args && cmd->command != cmd->args[0])
		free(cmd->command);
	free_tab(path_env_tab);
	free_tab(cmd->args);
}

static int	print_command_error(char *command_name, char **path_env_tab)
{
	if (path_env_tab == NULL && access(command_name, F_OK) == 0
		&& access(command_name, X_OK) != 0)
	{
		perror(command_name);
		return (126);
	}
	if (path_env_tab == NULL && access(command_name, X_OK) != 0)
		perror("execve");
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(command_name, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	return (127);
}

void	exec_command_or_exit(char *input, char **env)
{
	t_comargs	cmd;
	char		**path_env_tab;

	cmd.args = tab_env(input);
	cmd.command = NULL;
	path_env_tab = NULL;
	if (!cmd.args || !cmd.args[0])
	{
		free_tab(cmd.args);
		exit(127);
	}
	if (contain_slash(cmd.args[0]))
		cmd.command = cmd.args[0];
	else
	{
		path_env_tab = get_path_env_tab(env);
		cmd.command = get_valid_command(cmd.args, path_env_tab);
	}
	if (cmd.command && access(cmd.command, X_OK) == 0)
		execve(cmd.command, cmd.args, env);
	cmd.exit_status = print_command_error(cmd.args[0], path_env_tab);
	free_command_data(&cmd, path_env_tab);
	exit(cmd.exit_status);
}

void	close_fds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
