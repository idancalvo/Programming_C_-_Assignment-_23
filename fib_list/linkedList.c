#include "linkedList.h"

/*
*	Realizing the functions of the linked list
*	Insert, print, Close the list, release
*/




/*
*	Adds an item to the top of the list
*/
void insert2Head (ptr *p_list , unsigned long dataVal)
{
	ptr tempNode;				/*Create a new item for the list*/
	tempNode = (ptr) malloc (sizeof(item));

	if (!tempNode)				/*Check if we were able to create it*/
	{
		printf ("\n cannot allocate memory \n");
		exit(0);
	}
	
	tempNode->data = dataVal;		/*The introduction of the data*/
	tempNode->next = *p_list;		/*Update pointers in the list*/
	*p_list = tempNode;			/*Update the head of the list*/
}


/*
*	Closing the list and turning it into a circular list
*/
void closeList(ptr *p_list)
{
	ptr tempNode;
	tempNode = *p_list;
	
	while (tempNode->next) 			/*get on to the last item*/
	{
		tempNode = tempNode->next;
	}
	tempNode->next = *p_list;		/*the last item points to the first one*/
}


/*
*	Prints the list by the order of the items
*/	
void printlist(ptr *p_list)
{
	ptr tempNode;
	tempNode = *p_list;
	
	while ( *p_list != tempNode->next )	/*Moves on item*/
	{
		printf ("%ld\n",tempNode->data);
		tempNode = tempNode->next;
	}
	printf ("%ld\n",tempNode->data);	
	printf ("\n");
	
}


/*
*	free the memory of the list
*/
void freelist (ptr *p_list)
{
	ptr p1,p2;

	p1 = *p_list;
	p2 = p1->next;
	
	while (p1 != p2)	/*Moves on items and free them, Except from the first*/
	{
		p1->next = p2->next;
		free(p2);
		p2 =p1->next;
	}
	free (*p_list);		/*free the first item*/
}

