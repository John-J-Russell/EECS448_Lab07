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
	//make a test pointer
	Test* tester= new Test();
	//run the test function
	tester->testLinkedList();
	//delete test pointer
	delete(tester);
	//return
	return(0);
}
