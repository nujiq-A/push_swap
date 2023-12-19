/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:04:34 by qang              #+#    #+#             */
/*   Updated: 2023/12/19 17:18:02 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (false);
		else if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

void	ft_check_nums(char *str)
{
	char	**temp;
	int		i;

	temp = ft_split(str, ' ');
	i = 0;
	while (temp[i])
	{
		if (!ft_isnum(temp[i]))
		{
			ft_free_split(temp);
			ft_error();
		}
		i++;
	}
}

void	check_args(int ac, char **av)
{
	int		i;

	i = 1;
	if (i == ac)
		return ;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_check_nums(av[i]);
		else if (!ft_isnum(av[i]))
			ft_error();
		i++;
	}
}
