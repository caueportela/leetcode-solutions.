#include <stdio.h>
#include <stdlib.h>

/*
====================
ListNode
====================
*/
struct ListNode
{
	int val;
	struct ListNode* next;
};

/*
====================
RotateRight
 Rotates the list to the right by k positions
====================
*/
struct ListNode* rotateRight( struct ListNode* head, int k )
{
	if ( head == NULL || head->next == NULL ) {
		return head;
	}

	int size = 1;
	struct ListNode* first = head;

	while ( first->next != NULL ) {
		first = first->next; // o ultimo da lista
		size++;
	}  
   
	k = k % size;

	if ( k == 0 ) {
		return head;
	}

	struct ListNode* newFirst = head; // new first recebe a cabeça

	for ( int i = 0; i < size - k - 1; i++ ) {
		newFirst = newFirst->next;   
	}

	struct ListNode* newHead = newFirst->next;
	newFirst->next = NULL;
	first->next = head;

	return newHead;
}

/*
====================
FreeList
 Frees all nodes in the list
====================
*/
void FreeList( struct ListNode* head )
{
	struct ListNode* tmp;

	while ( head != NULL ) {
		tmp = head;
		head = head->next;
		free( tmp );
	}
}

/*
====================
Main
====================
*/
int main( void )
{
	int values[] = { 1, 2, 3, 4, 5 };
	int n = sizeof( values ) / sizeof( values[0] );

	struct ListNode* head = NULL;
	struct ListNode* curr = NULL;

	for ( int i = 0; i < n; i++ ) {
		struct ListNode* node = malloc( sizeof( struct ListNode ) );
		node->val = values[i];
		node->next = NULL;

		if ( head == NULL ) {
			head = node;
			curr = node;
		} else {
			curr->next = node;
			curr = curr->next;
		}
	}

	printf( "Original list: " );
	struct ListNode* temp = head;

	while ( temp != NULL ) {
		printf( "%d ", temp->val );
		temp = temp->next;
	}
	printf( "\n" );

	int k = 336;
	head = rotateRight( head, k );

	printf( "Rotate for %d: ", k );
	temp = head;

	while ( temp != NULL ) {
		printf( "%d ", temp->val );
		temp = temp->next;
	}
	printf( "\n" );

	FreeList( head );

	return 0;
}
