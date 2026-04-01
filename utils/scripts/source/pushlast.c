#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

char *last_modified(void)
{
	DIR *d;
	struct dirent *entry;
	struct stat st;
	char best_file[1024] = {0};
	time_t best_time = 0;
	char *result;

	d = opendir(".");
	if (!d) {
		perror("opendir");
		exit(1);
	}

	while ((entry = readdir(d)) != NULL) {
		if (entry->d_type == DT_DIR)
			continue;

		if (strstr(entry->d_name, ".git") != NULL)
			continue;

		if (stat(entry->d_name, &st) == -1)
			continue;

		if (st.st_mtime > best_time) {
			best_time = st.st_mtime;
			strncpy(best_file, entry->d_name, sizeof(best_file) - 1);
		}
	}

	closedir(d);

	if (best_file[0] == '\0') {
		printf("No files found.\n");
		exit(1);
	}

	/* allocate a copy to return */
	result = malloc(strlen(best_file) + 1);
	if (!result) {
		perror("malloc");
		exit(1);
	}
	strcpy(result, best_file);

	return result;
}

int main(int argc, char *argv[])
{
	char *file;
	char add[2048] = "git add ";
	char commit[4096] = "git commit -m ";
	char push[128] = "git push";
	char reset[128] = "git reset";
	char default_msg[] = "Formatting";
	int c;

	if (argc > 3) {
		printf("\nPlease use: pl or pl <y/n> <\"commit\">\n");
		return 1;
	}

	/* find last modified file */
	file = last_modified();

	/* git add */
	strncat(add, file, sizeof(add) - strlen(add) - 1);
	system(add);

	/* git commit */
	if (argc == 3) {
		strncat(commit, argv[2], sizeof(commit) - strlen(commit) - 1);
	}
	else
	{
		strncat(commit, default_msg, sizeof(commit) - strlen(commit) - 1);
	}
	system(commit);

if (argc == 1)
{
	/* auto-confirm push */
	system(push);
	printf("\n%s pushed to git.\n\n", file);
}
else if (argc == 2)
{
	if (strcmp(argv[1], "y") == 0)
	{
		system(push);
	}
	else
	{
		printf("\nPush %s to GitHub? (y/n): ", file);
		fflush(stdout);

		do {
			c = getchar();
		} while (c == '\n' || c == '\r');

		if (c == 'y' || c == 'Y')
		{
			system(push);
			printf("\n%s pushed to git.\n\n", file);
		}
		else
		{
			system(reset);
			printf("\n%s unstaged, nothing will be pushed.\n\n", file);
		}
	}
}

	free(file);
	return 0;
}
