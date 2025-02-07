/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:55:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 20:30:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	array_length(char **av)
{
	size_t i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

char **array_join(char **array, char *newstr)
{
	char **new_array;
	size_t len;
	size_t	i;
	
	if (!newstr)
		return (array);
	len = array_length(array);
	new_array = malloc((len + 2) * sizeof(char *));
	if (!new_array)
		return (free_array(array), free(newstr), NULL);
	i = 0;
	while (array && array[i])
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = newstr;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}
