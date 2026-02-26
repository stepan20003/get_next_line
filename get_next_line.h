/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25                                  #+#    #+#             */
/*   Updated: 2026/02/25                                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>   // read
# include <stdlib.h>   // malloc, free

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *s, int c);
int      ft_strlen(char *s);
char    *ft_get_line(char *remainder);
char    *ft_get_remainder(char *remainder);

#endif