/*
	@AUTHOR: JOHN RUSSELL j362r647@ku.edu
	@DATE: 22 April 2016
	@FILE: test.h
	@PURPOSE: lists the test classes and variables
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Node.h"
#include "LinkedList.h"

class Test
{
	public:
	/*
		@PRE: nothing
		@POST: prints to console results of test
		@RETURN: nothing
	*/
	void testLinkedList();
	

	private:

	/*
		@PRE: I don't think it'll work if  m_list1 hasn't been instantiated,
			though I'm not absolutely certain.
		@POST: Deletes list, creates new and empty one from the ashes.
		@RETURN: no actual return.
	*/
	void refreshLinkedList();

	//an uncreatively-named LinkedList pointer
	LinkedList<int>* m_list1;

	//tracks bug total
	int m_bugCount;
	//tracks test total
	int m_testCount;

};
#endif
