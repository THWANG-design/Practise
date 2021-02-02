#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 10
char* s_gets(char* st, int n);
struct book {
	char title[MAXTITLE];
	char author[MAXAUTL];
	float value;

};
void main()
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);
	pbooks = fopen_s("book.dat", "a+b");
	if (pbooks == NULL)
	{
		puts("Can not open this book.dat file", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contens of book.dat:");
		printf("%s by %s $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is full", stderr);
		exit(2);
	}
	puts("Please add new book titiles");
	puts("Press [Enter] to quit");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITLE) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Enter the author : ");
		s_gets(library[count].author, MAXTITLE);
		puts("Now enter the value");
		scanf_s("%f", &library[count].value);
		

		count++;
		if (count < MAXBKS)
			puts("Enter the nest title");
	}
	if (count > 0)
	{
		puts("Here is the list of your books : ");
		for (index = 0; index < count; index++)
			printf("%s by %s : $%.2f\n", library[index].title,
				library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("No books, it is bad");
	puts("bye");
	fclose(pbooks);
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
			while (getchar() != '\n')
				continue;
		return rel;

	}
}
