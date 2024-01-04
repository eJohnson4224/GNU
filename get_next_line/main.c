/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:23:47 by jebitrus          #+#    #+#             */
/*   Updated: 2023/08/22 21:34:13 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{	
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open("test-files/text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("\nline %i: %s", i, line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
	}
	//printf("line %i: %s", i, line);
	if (close(fd) == -1)
	{
		printf("Failed to close the file\n");
		return (1);
	}
	if (line == NULL)
		printf("line returns NULL.\n");
	line = get_next_line(fd);
	if (line == NULL)
		printf("line returns NULL.\n");

	return (0);
}
