/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:03:02 by edmatevo          #+#    #+#             */
/*   Updated: 2025/03/29 14:50:22 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_into_buffer(int fd, char *left_str, char *buff)
{
	int		bytes_read;
	char	*temp;

	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_str);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!left_str)
			left_str = ft_strdup("");
		temp = left_str;
		left_str = ft_strjoin(temp, buff);
		if (!left_str)
			return (NULL);
		if (ft_strchr(left_str, '\n'))
			break ;
	}
	return (left_str);
}

static char	*extract_line(char	*line)
{
	char	*result;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		result = NULL;
	line[i + 1] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*left_str[1024] = {NULL};
	char		*read_line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_line = read_into_buffer(fd, left_str[fd], buff);
	free(buff);
	if (!read_line || *read_line == '\0')
	{
		free(read_line);
		buff = NULL;
		left_str[fd] = NULL;
		return (NULL);
	}
	buff = NULL;
	left_str[fd] = extract_line(read_line);
	return (read_line);
}

// int main()
// {
//     int fd1 = open("./file1.txt", O_RDONLY);
//     int fd2 = open("./file2.txt", O_RDONLY);

//     char *line1;
//     char *line2;
//     int i = 0;
//     while(i < 10)
//     {
//         line1 = get_next_line(fd1);
//         line2 = get_next_line(fd2);

//         if (line1)
//         {
//             printf("File1:\n%s", line1);
//             free(line1);
//         }
//         if (line2)
//         {
//             printf("\nFile2:\n%s", line2);
//             free(line2);
//         }
//         i++;
//     }
// }