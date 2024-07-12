/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:40:44 by mapierre          #+#    #+#             */
/*   Updated: 2024/06/26 21:01:35 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_frees(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (start > len)
	{
		free(s);
		return (NULL);
	}
	str = malloc(((len - start) + 1) * sizeof(char));
	if (!str)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (s[start] && start < len)
		str[i++] = s[start++];
	str[i] = '\0';
	free(s);
	return (str);
}

char	*ft_create_line(char *memo, int n)
{
	char	*line;
	int		c;
	int		cp;

	cp = 0;
	if (!memo)
		return (NULL);
	c = ft_strlen(memo);
	if (c == 0)
		return (NULL);
	line = malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	while (cp <= n)
	{
		line[cp] = memo[cp];
		cp++;
	}
	line[cp] = '\0';
	return (line);
}

char	*join_to_memo(char *memo, char *buf)
{
	char	*tmp;

	if (!memo)
	{
		memo = malloc(sizeof(char) * 1);
		if (!memo)
			return (NULL);
		memo[0] = '\0';
	}
	tmp = ft_strjoin(memo, buf);
	free(memo);
	memo = tmp;
	return (memo);
}

char	*read_join(char *memo, int fd, char **line)
{
	int		lu;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	lu = read(fd, buf, BUFFER_SIZE);
	if (lu <= 0)
	{
		free(buf);
		if (memo && *memo != 0)
			*line = ft_strdup(memo);
		free(memo);
		return (NULL);
	}	
	buf[lu] = '\0';
	memo = join_to_memo(memo, buf);
	free(buf);
	return (memo);
}

char	*get_next_line(int fd, int booleen)
{
	static char	*memo[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = 0;
	if (booleen)
	{
		free(memo[fd]);
		memo[fd] = NULL;
		return (NULL);
	}
	while (ft_get_n(memo[fd]) == -1)
	{
		memo[fd] = read_join(memo[fd], fd, & line);
		if (memo[fd] == NULL)
			return (line);
	}
	line = ft_create_line(memo[fd], ft_get_n(memo[fd]));
	if (!line)
		return (free(memo[fd]), NULL);
	memo[fd] = ft_substr_frees(memo[fd], ft_strlen(line), ft_strlen(memo[fd]));
	if (!memo[fd])
		return (free(line), NULL);
	return (line);
}
/*
int	main(void) 
{
 	int	fd;

 	fd = open("bible.txt", O_RDONLY);
 	char *str;

 	str = 0;
 	while ((str = get_next_line(fd)))
 	{
 		printf("%s", str);
 		free(str);
 	}
 	printf("%s ", str);
 	return (0);
}*/
