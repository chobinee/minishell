/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:58:42 by soulee            #+#    #+#             */
/*   Updated: 2023/03/04 22:32:28 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_env_list *env_list, char *key)
{
	t_env_list	*temp;

	while (env_list)
	{
		if (!ft_strncmp(env_list->key, key, ft_strlen(key)))
		{
			temp = env_list;
			env_list = env_list->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
		env_list = env_list->next;
	}
}

void	env(t_env_list *env_list)
{
	char	**envp;

	envp = convert_env_list_to_arr(env_list);
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
