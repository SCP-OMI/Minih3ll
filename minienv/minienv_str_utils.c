#include "../minishell.h"

char	*name_only(char *key_pair)
{
	int	i;

	i = 0;
	while ((key_pair[i] != '=' && key_pair[i] != '+') && key_pair[i])
		i++;
	return (ft_substr(key_pair, 0, i));
}

char	*value_only(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	if (!key_pair[i])
		return (NULL);
	return (&key_pair[i + 1]);
}

char	*create_keypair(char *name, char *value)
{
	char	*key_pair;
	int		key_pair_size;
	int		i;

	key_pair_size = ft_strlen(name);
	if (value)
		key_pair_size += ft_strlen(value);
	key_pair = malloc((key_pair_size + 2) * sizeof(char));
	i = 0;
	while (name && *name)
		key_pair[i++] = *name++;
	if (value)
		key_pair[i++] = '=';
	while (value && *value)
		key_pair[i++] = *value++;
	key_pair[i] = '\0';
	return (key_pair);
}
