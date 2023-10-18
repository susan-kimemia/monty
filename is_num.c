#include "monty.h"

/**
 * __isNamba - checks leading character of operand read
 * @c: argument read
 * Return: 1 if true else 0
 *
 */
int __isNamba(char *c)
{
int i = 0;

while (c[i] != '\0')
{
if (!((c[i] >= '0' && c[i] <= '9') || (c[i] == '+') || (c[i] == '-')))
{
return (0);
}
i++;
}

return (1);
}
