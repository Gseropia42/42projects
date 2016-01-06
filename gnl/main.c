#include "get_next_line.h"

int main(int agc, char **argv)
{
			char *line;
					line = NULL;

							if (agc != 2)
											ft_putstr("lol tocard");

									int fd;
											int i;
													i= 0;
															fd = open(argv[1], O_RDONLY);

																	if (fd == -1)
																					ft_putstr("lol tocard");
																			while ((i = get_next_line((int const)fd, &line)) > 0)
																						{
																											ft_putendl(line);
																																			free(line);
																																					}
																					ft_putnbr(i);
																							close(fd);
																									return (0);
}
