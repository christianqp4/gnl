/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chquinde <chquinde@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:21:25 by chquinde          #+#    #+#             */
/*   Updated: 2025/03/13 16:30:12 by chquinde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	while (s1[i])
		nstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		nstr[j++] = s2[i++];
	nstr[j] = 0;
	free (s1);
	return (nstr);
}

char	*ft_strdup(const char *s)
{
	char	*nstr;
	size_t	i;

	nstr = malloc(ft_strlen(s) + 1);
	if (!nstr)
		return (NULL);
	i = 0;
	while (*s)
		nstr[i++] = *s++;
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	i = 0;
	ch = (char)c;
	if (ch == '\0')
	{
		while (s[i])
			i++;
		return ((char *)&s[i]);
	}
	while (s[i])
	{
		if ((*(s + i)) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (0);
	if (dstsize > 0)
	{
		while (*src != '\0' && i < (dstsize - 1))
		{
			*dest++ = *src++;
			i++;
		}
		*dest = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
