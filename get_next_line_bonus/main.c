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
#include <time.h>

#define	NUM_LINES	20
#define	FILES_COUNT	15

char	*FILES[]	=	{
	"test-files/file.txt",
	"test-files/file2.txt",
	"test-files/file3.txt",
	"test-files/empty.txt",
	"test-files/only_newline.txt",
	"test-files/bar.txt",
	"test-files/file4.txt",
	"test-files/file5.txt",
	"test-files/file6.txt",
	"test-files/64bit_line.txt",
	"test-files/64bit_paragraph.txt",
	"test-files/fewchar_perline.txt",
	"test-files/long_line.txt",
	"test-files/normal.txt",
	"test-files/text.txt"
};

int TEST_FDS[FILES_COUNT];

int	main(void)
{	
	printf("\nRunning for %i lines on %i files\n", NUM_LINES, FILES_COUNT);

	for (int test_file_index = 0; test_file_index < FILES_COUNT; test_file_index++) {
		TEST_FDS[test_file_index] = open(FILES[test_file_index], O_RDONLY);
	}

	int curr_line_num = 1;

	while (curr_line_num <= NUM_LINES) {
		printf("================================================================================================= Line %i \n", curr_line_num);

		for (int test_file_index = 0; test_file_index < FILES_COUNT; test_file_index++) {
			char	*file_name = FILES[test_file_index];
			char	*next_line = get_next_line(TEST_FDS[test_file_index]);

			printf("%s: %s\n", file_name, next_line);
			free (next_line);
		}

		curr_line_num++;
	}

	return (0);
}

// Original test function:
//
// int	main(void) //bonus test
// {
// 	int	fd;
// 	int	fd2;
// 	int	fd3;
// 	char	*line;

// 	fd	=	open("test-files/file.txt", O_RDONLY);
// 	fd2	=	open("test-files/file2.txt", O_RDONLY);
// 	fd3	=	open("test-files/file3.txt", O_RDONLY);

// 	line	=	get_next_line(fd);
// 	printf("file : %s", line);

// 	line	=	get_next_line(fd2);
// 	printf("\nfile2 : %s", line);

// 	line	=	get_next_line(fd3);
// 	printf("\nfile3 : %s", line);

// 	line	=	get_next_line(fd3);
// 	printf("\nfile3 : %s", line);

// 	line	=	get_next_line(fd2);
// 	printf("\nfile2 : %s", line);

// 	line	=	get_next_line(fd);
// 	printf("\nfile : %s", line);

// 	line	=	get_next_line(fd);
// 	printf("\nfile : %s", line);

// 	return (0);
// }
