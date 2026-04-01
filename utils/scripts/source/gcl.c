#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char command[512] = "git clone ", repo[256], addr[512];
	char *abbrv = "holbertonschool-";

	if (argc < 3)
	{
		printf("Usage: gcl <username> <repository>\n");
		return 1;
	}

	strcpy(repo, argv[2]);

	if (tolower(argv[2][0]) == 'h' && tolower(argv[2][1]) == 's')
	{
		if (tolower(argv[2][2]) == 'l' &&
			tolower(argv[2][3]) == 'l' &&
			tolower(argv[2][4]) == 'p')
		{
			strcpy(repo, "holbertonschool-low_level_programming");
		}
		else
		{
			strcpy(repo, abbrv);
			strcat(repo, argv[2] + 2);
		}
	}

	snprintf(addr, sizeof(addr),
			 "https://www.github.com/%s/%s", argv[1], repo);

	if (strlen(addr) < 4 || strcmp(addr + strlen(addr) - 4, ".git") != 0)
		strcat(addr, ".git");

	strcat(command, addr);

	system(command);
	return 0;
}
