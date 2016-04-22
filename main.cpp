/*
	@AUTHOR: JOHN RUSSELL j362r647@ku.edu
	@DATE: 22 April 2016
	@FILE: main.c
	@PURPOSE: makes test class go
*/
#include "Test.h"
#include "Node.h"
#include "LinkedList.h"


int main()
{
	Test* tester= new Test();

	tester->testLinkedList();

	delete(tester);

	return(0);
}
