#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char	user[100];
	char	buf_file[48];
	char	pass[100];

	memset(user, '\0', 12);
	memset(buf_file, '\0', 5);
	memset(pass, '\0', 12);

	FILE *file;
	file = fopen("/home/users/level03/.pass", "r");
	if (file == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}

	size_t	file_size;
	file_size = fread(buf_file, 1, 41, file);

	int		i;
	i = strcspn(buf_file, "\n");
	buf_file[i] = 0x0;

	if (file_size != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(file);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");

	printf("--[ Username: ");
	fgets(user, 100, stdin);
	i = strcspn(user, "\n");
	buf_file[i] = 0x0;

	printf("--[ Password: ");
	fgets(pass, 100, stdin);
	i = strcspn(pass, "\n");
	pass[i] = 0x0;

	puts("*****************************************");

	if (strncmp(buf_file, pass, 41) == 0)
	{
		printf("Greetings, %s!\n", user);
		system("/bin/sh");
		return 0;
	}
	printf(user);
	puts(" does not have access!");
	exit(1);
}
%22$016llx %23$016llx %24$016llx %25$016llx %26$016llx
%22$p %23$p %24$p %25$p %26$p