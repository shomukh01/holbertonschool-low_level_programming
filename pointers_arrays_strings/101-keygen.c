#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int sum = 0;
	int i;
	char password[84];

	srand(time(NULL));

	for (i = 0; sum < 2772; i++)
	{
		password[i] = rand() % 94 + 33;
		sum += password[i];
	}

	password[i - 1] += 2772 - sum;
	password[i] = '\0';

	printf("%s", password);

	return (0);
}
