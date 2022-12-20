/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gity.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:43:48 by victofer          #+#    #+#             */
/*   Updated: 2022/12/20 12:23:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

void	errors(char *msg)
{
	printf("ERROR: %s", msg);
	exit(-1);
}

static char	*ft_join(char *strjoin, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	strjoin = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	strjoin = ft_join(strjoin, s1, s2);
	return (strjoin);
}

void	make_command(char *commit, char *command)
{
	chdir("..");
	printf("\033[0;33m* git add . \033[0;37m\n");
	system("git add .");
	printf("\033[0;33m* %s \033[0;37m\n", command);
	if (system(command) == 0)
	{
		system(command);
		printf("\033[0;33m* git push \033[0;37m\n");
		system("git push");
	}
}

int	main(int argc, char **argv)
{
	char	*commit;
	char	*join;
	char	*join2;
	char	*command;

	if (argc != 2)
		errors("No Commit message? 😡");
	commit = "git commit -m ";
	join = ft_strjoin(commit, "'");
	join2 = ft_strjoin(join, argv[1]);
	free(join);
	command = ft_strjoin(join2, "'");
	free(join2);
	make_command(commit, command);
	free (command);
	return (0);
}
