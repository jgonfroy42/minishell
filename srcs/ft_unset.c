/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:30:30 by jgonfroy          #+#    #+#             */
/*   Updated: 2020/12/22 10:30:34 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	**remove_env(char **env, int index)
{
	int		i;
	int		j;
	int		size;
	char	**tab;

	i = 0;
	j = 0;
	size = size_env(env);
	tab = ft_calloc(sizeof(char*), size);
	while (i < size - 1)
	{
		if (j == index)
			j++;
		tab[i] = ft_strdup(env[j]);
		i++;
		j++;
	}
	free_strarray(env);
	return (tab);
}

int		ft_unset(t_var *shell, char **cmd)
{
	int		i;
	int		index;
	t_env	tmp;

	i = 1;
	while (cmd[i])
	{
		tmp = split_env(cmd[i]);
		if (tmp.content)
			error_id(cmd[i]);
		else if ((is_valid_id(tmp.name, cmd[i])))
		{
			if ((index = is_in_env(shell->env, tmp.name)))
				shell->env = remove_env(shell->env, index);
		}
		free(tmp.name);
		free(tmp.value);
		i++;
	}
	return (0);
}