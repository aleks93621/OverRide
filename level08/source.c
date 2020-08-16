#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void	log_wrapper(FILE *logfile, char *prefix, char *filename)
{
	char buf[255];
	strcpy(buf, prefix);
	snprintf(buf[strlen(buf) - 1], 255 - strlen(buf), filename);
	buf[strcspn(buf, "\n")] = 0;
	fprintf(logfile, "LOG: %s\n", buf)
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("Usage: %s filename\n", av[0]);

	FILE	*logfile = fopen("./backups/.log", "w");

	if (logfile == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(logfile, "Starting back up: ", av[1]);
	FILE	*avfile = fopen(av[1], "r");

	if (avfile == 0)
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}

	char	buf[100];
	strcpy(buf, "./backups/");
	strncat(buf, av[1], 99 - strlen(buf) - 1);

	int fd;
	fd = open(buf, 0xc1, 0x1b0);

	if (fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}

	char c;
	while (c = fgetc(avfile) != 255)
		write(fd, &c, 1);

	log_wrapper(logfile, "Finished back up ", av[1]);
	fclose(logfile);
	close(fd);
	return 0;
}