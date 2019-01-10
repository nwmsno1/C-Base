#include <stdio.h>
#include <string.h>

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};


//function declare
void printBook( struct Books book );
int main()
{
	struct Books Book1;
	struct Books Book2;

	//Book1
	strcpy( Book1.title, "C Programming");
	strcpy( Book1.author, "Nuha Ali");
	strcpy( Book1.subject, "Telecom Biling Tutorial");
	Book1.book_id = 6495407;

	//Book2
	strcpy( Book2.title, "Telecom Billing");
	strcpy( Book2.author, "Zara Ali");
	strcpy( Book2.subject, "Telecom Billing Tutorial");
	Book2.book_id = 6495700;
	
	/* 输出 Book1 信息 */
	printBook(Book1);

   	/* 输出 Book2 信息 */
	printBook(Book2);
	
	return 0;
}

void printBook( struct Books book )
{
	printf( "Book title : %s\n", book.title);
        printf( "Book author : %s\n", book.author);
        printf( "Book subject : %s\n", book.subject);
        printf( "Book book_id : %d\n", book.book_id);

}

