/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chquinde <chquinde@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:12:46 by chquinde          #+#    #+#             */
/*   Updated: 2025/03/13 12:41:15 by chquinde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Devuelve str con o sin '\n', str vacia si ya hemos leido todo el archivo o NULL fallo
char	*read_file(char *full_line, int fd)
{
	int		chars_read;
	char	*read_buf;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (read_buf == NULL)
		return (NULL);
	chars_read = read (fd, read_buf, BUFFER_SIZE);
	while (chars_read > 0)
	{
		read_buf[chars_read] = '\0';
		full_line = ft_strjoin(full_line, read_buf);
		if (ft_strchr(read_buf, '\n'))
		{
			free (read_buf);
			return (full_line);
		}
		chars_read = read(fd, read_buf, BUFFER_SIZE);
	}
	free (read_buf);
	if (chars_read == 0)
		return (full_line);
	else
		return (NULL);
}

//Recibe una str con '\n'. Devuelve una nueva str hasta el '\n'.
//Que pasa si no hay '\n'?
//full_line = "9abc"
char	*extract_line(char *full_line)
{
	char	*linea;
	int		i;

	i = 0;
	while (*full_line != '\n' && *full_line != '\0')
	{
		full_line++;
		i++;
	}
	if (*full_line == '\n')
	{
		linea = malloc(i + 2);
		ft_strlcpy (linea, full_line - i, i + 2);
	}
	else
	{
		linea = malloc(i + 1);
		ft_strlcpy (linea, full_line - i, i + 1);
	}
	return (linea);
}

//Recibe una str con '\n'. Devuelve una copia despues del '\n'
//Que pasa si no hay '\n'?
char	*rest_line(char *full_line)
{
	int		i;
	int		j;
	char	*resto;

	i = 0;
	j = 0;
	while (*full_line != '\n' && *full_line != '\0')
	{
		full_line++;
		i++;
	}
	if (*full_line == '\n')
		full_line++;
	while (*full_line != '\0')
	{
		full_line++;
		j++;
	}
	resto = malloc(j + 1);
	if (resto == NULL)
		return (NULL);
	ft_strlcpy (resto, full_line - j, j + 1);
	return (resto);
}

char	*get_next_line(int fd)
{
	char		*full_line;
	char		*linea;
	static char	*resto;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = resto;
	full_line = read_file(full_line, fd);
	if (full_line == NULL || *full_line == '\0')
	{
		free (resto);
		resto = NULL;
		return (NULL);
	}
	linea = extract_line (full_line);
	resto = rest_line (full_line);
	free (full_line);
	return (linea);
}
/*
int main()
{
	//int fd = open ("file.txt", O_RDONLY);
	int fd = -1;
  	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	printf("---null");
}*/
// 107 0 . manejar fd -1 ... free (restos) restos = NULL; return NULL
//1 . nombre bien puesto .. en get_next_line.c 
//2 mas protottipo en .h
//poner .. no... simple read_line sin que gestione fd = -1... esta bien
// ya que solo cambiaste donde read_buf[chars_read] .. dentro del bucle (char_read > 0 )
//3. de la version de 42...
// 3. Arreglar condicion al final de read_file, en caso de salir si chars_read > 0 returna NULL siempre...