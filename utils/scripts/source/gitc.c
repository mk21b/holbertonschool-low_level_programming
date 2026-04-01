#include <stdlib.h>

void main(void)
{
	system("git config --global user.name \"bfrasholb\"");
	system("git config --global user.email \"13065@holbertonstudents.com\"");
	system("git config --global credential.helper 'cache --timeout=720000'");
	system("git config advice.addIgnoredFile false");
}