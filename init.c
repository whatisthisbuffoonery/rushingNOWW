/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthoo <dthoo@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:02:41 by dthoo             #+#    #+#             */
/*   Updated: 2025/08/11 19:07:54 by dthoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//make error checking for every definition of valid map, besides the third one
//use open O_RDWR, we are not storing 2.14GB of malloc for internal pencil data of length INT_MAX * num of columns
//[0]: empty
//[1]: trap
//[2]: answer
//[3]: pencil
//[4]: null you moron

int	pls_count(char *buffer)
{
	int	i;

	i = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i ++;
	}
	return (0);
}

int	**malloc_pls_uwu(char *buffer, char trap)
{
	int	**arr;
	int	i;
	int	count;

	i = 0;
	count + 0;
	while (buffer[i])
	{
		if (buffer[i] == trap)
			count ++;
		i ++;
	}
	arr = malloc(count * sizeof(int *));
	i = 0;
	while (i < count)
		arr[i++] = malloc(3 * sizeof(int));
	return (arr);
}

int	**trap_init(char *buffer, char *using_chars, size_t size, int col)
{
	int	i;
	int	**traps;
	int	trap;

	i = 0;
	traps = malloc_pls_uwu(buffer, using_chars[1]);
	while (buffer[i])
	{
		if (buffer[i] == using_chars[1])
		{
			traps[trap][0] = i % col;
			traps[trap][1] = i / col;
			traps[trap][2] = '\0';
		}
		i ++;
	}
	return (traps);
}

void	start_char_init(char *buffer, size_t size)
{
	int		row_count;
	int		col_count;
	int		i;
	char	using_chars[5];

	i = -1;
	using_chars[3] = 33;
	row_count = buffer[0] - 48;
	col_count = pls_count(buffer); // pls evict
	using_chars[0] = buffer[1];
	using_chars[1] = buffer[2];
	using_chars[2] = buffer[3];
	using_chars[4] = '\0';
	while (i < 3)
	{
		i ++;
		if (using_chars[3] == using_chars[i] && i != 3)
		{
			pencil += 1;
			i = 0;
		}
	}
	logic(buffer, using_chars, trap_init(buffer, using_chars, size, col_count ++));
}
