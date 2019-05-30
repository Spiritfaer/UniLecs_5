#include <stdio.h>
#include <stdint.h>
#include <mem.h>

/*
	Is it possible to make a string palindrome
	Можно ли строку сделать палиндромом

Task:
	Write a function, the CR will check whether it is possible to convert the string
	so that it becomes a palindrome.
Example:
 	"bob" => true
	"bbo" => true
	"cat" => false
 	"pullupifipullup" => true
 	"ca" => false
 	"c" => true

Задача:
	Написать функцию, ктр будет проверять можно ли преобразовать строку
	так, чтобы она стала палиндромом.
*/

int8_t	checking_string_is_polindrom(const char *str)
{
	uint32_t buff[256] = {0};
	uint32_t str_len = strlen(str);
	uint32_t flag = 0;
	const char *tmp = str;

	if (str_len & 1)
		return (1);
	else if (str_len & 2)
		return (0);

	while (*tmp)
		buff[*tmp++]++;
	while (*str)
	{
		if (buff[*str] & 1)
		{
			flag++;
			buff[*str]--;
		}
		str++;
	}
	if (flag > 1)
		return (0);
	return (1);
}

int main(void)
{
	char *str = "pullupifipullup";
	checking_string_is_polindrom(str) ? printf("True\n") : printf("False\n");
	return (0);
}
