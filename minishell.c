/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:24:12 by soulee            #+#    #+#             */
/*   Updated: 2023/03/23 18:02:06 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ascii_art(void)
{
	ft_printf("\nMewww  |\\      _,,,—,,_        \n");
	ft_printf("       /,`.-'`'   ._  \\-;;,_    \n");
	ft_printf("      |,4-  ) )_   .;.(  `'-'   \n");
	ft_printf("     '—''(_/._)-'(_\\_)     Mewww…   \n");
	ft_printf("  ___     _       _   _    _ _   "
		"                  ___ _        _ _ \n");
	ft_printf(" / __| __| |_  _ (_)_(_)__| (_)_ _"
		"  __ _ ___ _ _  / __| |_  ___| | |\n");
	ft_printf(" \\__ \\/ _| ' \\| '_/ _ \\/ _` | | "
		"' \\/ _` / -_) '_| \\__ \\ ' \\/ -_) | |\n");
	ft_printf(" |___/\\__|_||_|_| \\___/\\__,_|_"
		"|_||_\\__, \\___|_|   |___/_||_\\___|_|_|\n");
	ft_printf("                                   "
		"|___/                            \n");
	ft_printf("                                       "
		"       Mewww…                      \n");
	ft_printf("\n");
}

int	main(int argc, char *argv[], char **envp)
{
	char			*line;
	int				status;
	t_env_list		*env_list;
	t_cmd_list		*cmd_list;

	line = NULL;
	env_list = NULL;
	cmd_list = NULL;
	if (argc != 1)
	{
		print_error("arguments error");
		exit(1);
	}
	parse_envp(&env_list, envp);
	print_ascii_art();
	while (1)
	{
		line = readline("🐈 $ ");
		if (!line)
			break ;
		if (*line != '\0')
		{
			add_history(line);
			cmd_list = parse_line(&cmd_list, line);
			parse_dollar_sign(cmd_list, env_list);
			iter_node(cmd_list);
			status = execute(cmd_list, env_list, count_cmd_list_node(cmd_list, TYPE_PIPE) + 1);
			clear_cmd_list(&cmd_list);
		}
		free(line);
		line = NULL;
	}
}
