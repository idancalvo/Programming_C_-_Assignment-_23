/*	Header Files	*/
#include "fib_list.h"



/*
*	Saving and printing Fibonacci series.
*	receive input from the user
*	creating a linked list
*	and put any number from the series in item of the list
*/

int main (void)
{

	int n;
	ptr list_head = NULL;											
	n = receiveInput();
													
	list_head = build (n);
	printf ("\nYou asked to print the elements of Fibonacci series up to fib(%d)\n",n);
	printlist (&list_head);
	freelist (&list_head);
	
	return 0;
}

/*
*	receive input from the user and checks if it valid
*/
int receiveInput()
{
	int n;
	int received;				/*Ensures proper input*/
	char tempc;
	
	printf ("hi,\nPlease enter a number \nand you will get this number of elements from Fibonacci series.\n");
	received=scanf("%d",&n);		/*Receiving and saving input in n*/
	
	/*Check that the input is correct and there are no unnecessary characters */
	while ( ( (tempc=getchar()) == ' ') || (tempc == '\t'));	
	if (tempc!='\n'|| received!=1 || n<0)
	{
		printf("you entered invalid number\n");
		exit(0);
	}
	
	return n;	
}


/*
*	Initializes and builds the list with Fibonacci series values
*/
ptr build (int n)
{
	ptr list_head;
	unsigned long fib_n, fib_m, temp;	/*Variables for calculating the Fibonacci series*/
	fib_n = 1;
	fib_m = 0;
	
	insert2Head(&list_head,fib_n);		/*Create an item fib(0)*/
	list_head->next=NULL;			/*Initializes a pointer to the end of the list*/
	
	while (n)				/*Insertion of items from the smallest to the bigest*/
	{
		insert2Head(&list_head,(fib_n+fib_m));
		temp = fib_n;
		fib_n = fib_n + fib_m;
		fib_m = temp;
		n--;
	}
	closeList(&list_head);			/*Closing the list (making it circular)*/
	return list_head;
}



