/*
	@AUTHOR: JOHN RUSSELL j362r647@ku.edu
	@DATE: 22 April 2016
	@FILE: Test.c
	@PURPOSE: Defines all the testing methods
*/


#include "Test.h"

/*
	THINGS TO TEST:
	Size on start
	isEmpty and size() working?
	IS THERE AN ENTRY AT THE BEGINNING, OR IS SIZE JUST STARTING AT ONE
	adding front and adding back
		likewise removing those
		likewise size iterating with them
	

*/


void Test::testLinkedList()
{
	m_list1 = new LinkedList<int>();
	//tracks bug total
	m_bugCount=0;
	//tracks test total
	m_testCount=0;
	//used for the purpose of checking size incrementation
	int initialSize=m_list1->size();
	
//////////////////////////////////////////////////////////////////////////////////////////////////
	//check return of size() on creation
	std::cout<<"1) Testing for size() on creation: \n";
	m_testCount++;
	if(m_list1->size()!=0)
	{
		std::cout<<"	FAILED: size does not return zero upon creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: size is zero upon creation \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
	//check return of isEmpty() on creation
	std::cout<<"2) Testing isEmpty() on creation: \n";
	m_testCount++;
	if(!m_list1->isEmpty())
	{
		std::cout<<"	FAILED: isEmpty does not return true on creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: list is empty on creation \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
	//uses toVector (guaranteed to work) to check the actual size on creation.
	std::cout<<"3) Does list actually start out empty? \n";
	m_testCount++;
	std::vector<int> listResults = m_list1->toVector();
	if(listResults.size() != 0)
	{
		std::cout<<"	FAILED: List is not empty upon creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: List is indeed empty upon creation \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
	//adds values from 0-9, checks if vector has correct values in correct place.
	std::cout<<"4) Does addFront work? \n";
	m_testCount++;
	//Add 10 entries to list using addFront
	for(int x=0; x<10; x++)
	{
		m_list1->addFront(x);
	}
	//cast results to vector
	listResults=m_list1->toVector();
	//bool for if bad thing tripped
	bool badFlag=false;
	//read out from the vector, and see if they match
	for(int x=0; x<listResults.size() ; x++)
	{
		if(listResults[9-x]!=x)
		{
			badFlag=true;
		}

	}

	if(badFlag==true)
	{
		std::cout<<"	FAILED: addFront is broken, and does not store values properly.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: addFront adds values properly. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
	//After having added 10 entries earlier, checks if current size() return
	//is 10 greater than the first size() return recorded at beginning of test function.
	std::cout<<"5) Checking if size incremented the correct number after adding 10 entries to front: \n";
	m_testCount++;
	if( (m_list1->size() - initialSize) == 10)
	{
		std::cout<<"	PASSED: Size has incremented correctly. \n";
	}
	else
	{
		std::cout<<"	FAILED: Size has not incremented correctly. \n";
		m_bugCount++;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////////////
	//removes 5 values using removeFront, checks if remainder match expected values.
	std::cout<<"6) Does removeFront remove values correctly? \n";
	m_testCount++;
	//reset badFlag
	badFlag=false;
	//removes the first 5 using removeFront
	for(int x=0; x<5; x++)
	{
		m_list1->removeFront();
	}
	//cast results to a vector
	listResults=m_list1->toVector();

	//tests if vector results are what they should be, given removeFront's parameters.
	for(int x=0; x<listResults.size(); x++)
	{
		if( listResults[4-x] != x)
		{
			badFlag=true;
		}			
	} 

	if(badFlag)
	{
		std::cout<<"	FAILED: removeFront does not work as expected. \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: removeFront performes to expectations. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////




	//I'm just going to refresh this list
	refreshLinkedList();




//////////////////////////////////////////////////////////////////////////////////////////////////
	//With fresh list, uses addBack to give 10 values, uses toVector to verify
	//legitimacy of results.
	std::cout<<"7) Does addBack work? \n";
	m_testCount++;
	//Add 10 entries to list using addFront
	for(int x=0; x<10; x++)
	{
		m_list1->addBack(x);
	}
	//cast results to vector
	listResults=m_list1->toVector();
	//bool for if bad thing tripped
	badFlag=false;
	//read out from the vector, and see if they match
	for(int x=0; x<listResults.size() ; x++)
	{
		if(listResults[x]!=x)
		{
			badFlag=true;
		}

	}

	if(badFlag==true)
	{
		std::cout<<"	FAILED: addBack is broken, and does not store values properly.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: addBack adds values properly. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////////////
	//Like last size check, uses size() function to see if size variable has
	//incremented correctly in conjunction with addBack()
	std::cout<<"8) Checking if size incremented the correct number after adding 10 entries to back: \n";
	m_testCount++;
	if( (m_list1->size() - initialSize) == 10)
	{
		std::cout<<"	PASSED: Size has incremented correctly. \n";
	}
	else
	{
		std::cout<<"	FAILED: Size has not incremented correctly. \n";
		m_bugCount++;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////


	



//////////////////////////////////////////////////////////////////////////////////////////////////
	//uses removeBack to pop 5 values from back, then uses toVector to check if 
	//they were actually removed. Note: this test depends on addBack() having
	//worked earlier.
	std::cout<<"9) Does removeBack remove values correctly (in conjunction with addBack)? \n";
	m_testCount++;
	//reset badFlag
	badFlag=false;
	for(int x=0; x<5; x++)
	{
		m_list1->removeBack();
	}
	listResults=m_list1->toVector();

	for(int x=0; x<listResults.size(); x++)
	{
		if( listResults[x] != x)
		{
			badFlag=true;
		}			
	} 

	if(badFlag)
	{
		std::cout<<"	FAILED: removeBack does not work as expected. \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: removeBack performes to expectations. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////



	//refresh the list
	refreshLinkedList();




//////////////////////////////////////////////////////////////////////////////////////////////////
	//Tests removeBack() after using the (priorly confirmed working) addFront() method
	//uses same tactics as last test.
	std::cout<<"10) Remove Back after using (working) addFront? \n";
	//populate list using known working method
	for (int x=0; x<10; x++)
	{
		m_list1->addFront(x);
	}
	m_testCount++;
	badFlag=false;
	for(int x=0; x<5 ; x++)
	{
		m_list1->removeBack();
	}

	listResults=m_list1->toVector();

	for(int x=0; x<listResults.size(); x++)
	{
		if(listResults[x]!=(9-x))
		{
			badFlag=true;
		}			
	}

	if(badFlag)
	{
		std::cout<<"	FAILED: removeBack does not perform to expectations.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: removeBack works as expected. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////




	//refresh again
	refreshLinkedList();




//////////////////////////////////////////////////////////////////////////////////////////////////
	//Using fresh "empty" list, tests removeBack() to see if it returns "false"
	//which is to indicate list is empty.
	std::cout<<"11) Does removeBack return false on an empty list? \n";
	m_testCount++;
	if(m_list1->removeBack())
	{
		std::cout<<"	FAILED: removeBack returned true on an empty list! \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: removeBack returned false on an empty list. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////



	//refresh again
	refreshLinkedList();




//////////////////////////////////////////////////////////////////////////////////////////////////
	//uses fresh "empty" list to see if it returns false on removeFront() call
	//indicating emptyness.
	std::cout<<"12) Does removeFront return false on an empty list? \n";
	m_testCount++;
	if(m_list1->removeFront())
	{
		std::cout<<"	FAILED: removeFront returned true on an empty list! \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: removeFront returned false on an empty list. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////




	//and refresh again
	refreshLinkedList();




//////////////////////////////////////////////////////////////////////////////////////////////////
	//Adds values to list, checks to see if search(value) detects all of them.
	std::cout<<"13) Does search(value) work? \n";
	m_testCount++;
	badFlag=false;
	for(int x=0; x<10; x++)
	{
		m_list1->addFront(x);
	}
	for(int x=0; x<10; x++)
	{
		if(m_list1->search(x))
		{
			//working baybee
		}
		else
		{
			badFlag=true;
		}
	}
	if(badFlag)
	{
		std::cout<<"	FAILED: search could not find one or more value \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"	PASSED: search found all expected values. \n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////


	//display program test results.
	std::cout<<"SCORE: " << (m_testCount - m_bugCount) << "/" << m_testCount <<"\n";

	//delete the list once finished
	delete(m_list1);
	return;
}

void Test::refreshLinkedList()
{
	delete m_list1;
	m_list1 = new LinkedList<int>();
	return;
}
