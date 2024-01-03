/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebitrus <jebitrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:23:47 by jebitrus          #+#    #+#             */
/*   Updated: 2023/08/22 21:34:13 by jebitrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("\nline %i: %s", i, line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
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
}*/
int	main(void) //bonus test
{
	int		fd;
	int		fd2;
	int		fd3;
    char    *line;
	fd = open("test-files/file.txt", O_RDONLY);
	fd2 = open("test-files/file2.txt", O_RDONLY);
	fd3 = open("test-files/file3.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("file : %s", line);
	line = get_next_line(fd2);
	printf("\nfile2 : %s", line);
	line = get_next_line(fd3);
	printf("\nfile3 : %s", line);
	line = get_next_line(fd3);
	printf("\nfile3 : %s", line);
	line = get_next_line(fd2);
	printf("\nfile2 : %s", line);
	line = get_next_line(fd);
	printf("\nfile : %s", line);
	line = get_next_line(fd);
	printf("\nfile : %s", line);
	return (0);
}
