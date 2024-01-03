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

#define	TEST_FILES_COUNT	8
#define	TEST_REPETITIONS	3

const	char	*TEST_FILES[]	=	{
	"test-files/file.txt",
	"test-files/file2.txt",
	"test-files/file3.txt",
	"test-files/long_line.txt",
	"test-files/64bit_line.txt",
	"test-files/64bit_paragraph.txt",
	"test-files/bar.txt",
	"test-files/empty.txt"
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
		printf("==================================\n");
		printf("  TEST REPETITION %i\n", repetition);
		printf("==================================\n\n");

		int test_file_index;

		for (test_file_index = 0; test_file_index < TEST_FILES_COUNT; test_file_index++) {
			char	*line;
			line = get_next_line(TEST_FDS[test_file_index]);
			printf("%s: %s\n", TEST_FILES[test_file_index], line);
		}

		repetition++;
	}

	return (0);
}
