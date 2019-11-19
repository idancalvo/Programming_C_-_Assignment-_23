/*	Header Files	*/
#include <stdio.h>
#include <stdlib.h>



/*	Defines list fields	*/
typedef struct node * ptr;

typedef struct node {
	unsigned long data;
	ptr next;
	}item;

