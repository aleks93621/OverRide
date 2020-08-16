#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

// Dans la fonction handle_msg en ASM
typedef struct 	s_user {	// [rbp-0xc0] = 192
	char	msg[140];		// 192 - 40 - 12 = 140
	char	name[40];		// [rax+0x20] = 32, 32 + 8(QWORD) = 40
	int		msglen;			// [rbp-0xc] = 12 = int
}				t_user;

void	secret_backdoor()
{
	char	buf[128];

	fgets(buf, 128, stdin);
	system(buf);
}

void	set_msg(t_user *user)
{
	char	buf[1024];

	bzero(buf, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buf, 1024, stdin);
	strncpy(user->msg, buf, user->msglen);
}

void	set_username(t_user *user)
{
	char	buf[128];

	bzero(buf, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 128, stdin);
	int i = 0;
	while (buf[i] <= 40 && buf[i] != 0)
	{
		user->name[i] = buf[i];
		i++;
	}
	printf(">: Welcome, %s", user->name);
}

void	handle_msg()
{
	t_user user;

	bzero(user.name, 40);
	user.msglen = 40;
	set_username(&user);
	set_msg(&user);
	puts(">: Msg sent!");
}

int 	main(int ac, char **av)
{
	puts("--------------------------------------------\n"\
		"|   ~Welcome to l33t-m$n ~    v1337        |\n"\
		"--------------------------------------------");

	handle_msg();
}