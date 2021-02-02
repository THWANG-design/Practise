#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 81
char* s_get(char* st, int n);
void eatline(void);
void show(void(*fp)(char*), char* str);
void Toupper(char*);
void Tolower(char*);
void Transpose(char*);
char showmenu();

void main()
{
	char line[LEN];
	void(*pfun)(char*);
	char choice;
	char copy[LEN];
	puts("Enter a string (empty line to quit)");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u': pfun = Toupper;
			case 'l': pfun = Tolower;
			case 't': pfun = Transpose;

			}
			strcpy_s(copy, line);
			show(pfun, copy);
		}
		puts("Enter a string (Empty to quit)");

	}
	puts("Its over");

}
char showmenu(void)
{
	char ans;
	puts("Enter your choice");
	puts("'u' Uppercase          'l' Lowercase");
	puts("'t' Transposed         'n' No choice");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while (strchr("ultn", ans) == NULL)
	{
		puts("You must enter the right choice :");
		ans = tolower(getchar());
		eatline();

	}
	return ans;
}
void Toupper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void Tolower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else
			*str = tolower(*str);
		str++;
	}
}
void show(void(*fp)(char*), char* str)
{
	(*fp)(str);
	puts(str);
}

char* s_gets(char* st, int n)
{
	char* rel;
	char* find;
	rel = fgets(st, n, stdin);
	if (rel)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != 'o')
				continue;
	}
	return rel;
}

