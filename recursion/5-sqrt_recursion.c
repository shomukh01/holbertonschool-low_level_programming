/**
 * helper - finds natural square root
 * @n: number
 * @i: trial number
 * Return: sqrt or -1
 */
int helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (helper(n, i + 1));
}
