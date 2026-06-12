/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:31:27 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 00:54:40 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Allowed for temporary testing/debugging!

/*
** Disabled: this duplicate main() conflicted with main.c's main() at link
** time. Kept here for review (#if 0 block) since this was the dev test
** harness for the parser/flatten step.
*/
/*int	main(int argc, char **argv)
{
	char	**flat_array;
	int		i;
	int		error_flag;
	int		num;

	if (argc < 2)
		return (0);
	
	error_flag = 0;
	printf("--- STEP 1: Testing Flattening Engine ---\n");
	flat_array = input_split_and_flatten(argc, argv);
	if (!flat_array)
	{
		printf("Flattening failed or returned NULL\n");
		return (1);
	}
	i = 0;
	while (flat_array[i])
	{
		printf("Token [%d]: %s\n", i, flat_array[i]);
		
		// Optional: If you have filled in the code for these,
			uncomment them to test:
		/*
		printf("  -> Is valid digit? %d\n", is_valid_digit(flat_array[i]));
		num = safe_convert(flat_array[i], &error_flag);
		printf("  -> Converted int: %d (Error flag: %d)\n", num, error_flag);
		*/
		/*
		i++;
	}
	// Clean up the string array memory
	free_flat_array(flat_array);
	printf("\n--- Test Complete: Memory Freed ---\n");
	return (0);
}
*/