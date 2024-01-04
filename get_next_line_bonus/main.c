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

// Alternate test main. This one can be set for an abitrary number of repetitions
// and it outputs the related filename for each line it prints

#define	TEST_FILES_COUNT	3
#define	TEST_REPETITIONS	2

char	*TEST_FILES[]	=	{
    "test-files/file.txt",
    "test-files/file2.txt",
    "test-files/file3.txt",
    // "test-files/long_line.txt",
    // "test-files/64bit_line.txt",
    // "test-files/64bit_paragraph.txt",
    // "test-files/bar.txt",
    // "test-files/empty.txt"
};

int TEST_FDS[TEST_FILES_COUNT];

int	main(void)
{	
	printf("\nRepeating tests  %i times\n", TEST_REPETITIONS);

	int test_file_index;

	for (test_file_index = 0; test_file_index < TEST_FILES_COUNT; test_file_index++) {
		TEST_FDS[test_file_index] = open(TEST_FILES[test_file_index], O_RDONLY);
	}

	int repetition = 1;

	while (repetition <= TEST_REPETITIONS) {
		printf("\nREPETITION %i\n", repetition);
		printf("==================================\n");

		for (int test_file_index = 0; test_file_index < TEST_FILES_COUNT; test_file_index++) {
			char	*line;
			char	*file_name = TEST_FILES[test_file_index];
			line = get_next_line(TEST_FDS[test_file_index]);
			printf("%s: %s\n", file_name, line);
			free (line);
		}

		repetition++;
	}

	return (0);
}
