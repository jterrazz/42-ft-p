#include "../ft_p.h"

char *ft_strjoin_free(char *str1, char *str2, t_bool free1, t_bool free2)
{
	char *str;

	str = ft_strjoin(str1, str2);
	if (free1)
		free(str1);
	if (free2)
		free(str2);
	return (str);
}
