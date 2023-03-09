#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc < 2 || (argv[1] == NULL) || (argv[1][0] == '\0'))
	{
		printf("\n");
		return (1);
	}
	str = calloc(sizeof(argv[1] - 2), sizeof(char));
	i = -1;
	while (argv[1][i + 2] && ((i + 1) < (sizeof(argv[1]) - 2)))
	{
		++i;
		if (!isalpha(argv[1][i + 1]))
		{
			str[i] = argv[1][i + 1];
			continue ;
		}
		else if (argv[1][i + 1] > 'M')
		{
			str[i] = argv[1][i + 1] - 13;
			continue ;
		}
		else if (argv[1][i + 1] > 'm')
		{
			str[i] = argv[1][i + 1] - 13;
			continue ;
		}
		else
			str[i] = argv[1][i + 1] + 13;
	}
	printf("%s\n", str);
}
