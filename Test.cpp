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
	//
	m_list1 = new LinkedList<int>();
	//tracks bug total
	m_bugCount=0;
	//tracks test total
	m_testCount=0;
	//used for the purpose of checking size incrementation
	int initialSize=m_list1->size();
	

	std::cout<<"1) Testing for size() on creation: ";
	m_testCount++;
	if(m_list1->size()!=0)
	{
		std::cout<<"FAILED: size does not return zero upon creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: size is zero upon creation \n";
	}





	std::cout<<"2) Testing isEmpty() on creation: ";
	m_testCount++;
	if(!m_list1->isEmpty())
	{
		std::cout<<"FAILED: isEmpty does not return true on creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: list is empty on creation \n";
	}





	std::cout<<"3) Does list actually start out empty? ";
	m_testCount++;
	std::vector<int> listResults = m_list1->toVector();
	if(listResults.size() != 0)
	{
		std::cout<<"FAILED: List is not empty upon creation \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: List is indeed empty upon creation \n";
	}





	std::cout<<"4) Does addFront work? ";
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
			//std::cout<<"BAD THING: Vector not accurately reflecting addFront requirements " << listResults[x] << "\n";
			badFlag=true;
		}

	}

	if(badFlag==true)
	{
		std::cout<<"FAILED: addFront is broken, and does not store values properly.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: addFront adds values properly. \n";
	}






	std::cout<<"5) Checking if size incremented the correct number after adding 10 entries to front: ";
	m_testCount++;
	if( (m_list1->size() - initialSize) == 10)
	{
		std::cout<<"PASSED: Size has incremented correctly. \n";
	}
	else
	{
		std::cout<<"FAILED: Size has not incremented correctly. \n";
		m_bugCount++;
	}




	std::cout<<"6) Does removeFront remove values correctly? ";
	m_testCount++;
	//reset badFlag
	badFlag=false;
	for(int x=0; x<5; x++)
	{
		if(m_list1->removeFront())
		{
			//std::cout<<"Value removed. \n";
		}
		else
		{
			//std::cout<<"function claims value not removed. \n";
		}
	}
	listResults=m_list1->toVector();

	for(int x=0; x<listResults.size(); x++)
	{
		if( listResults[4-x] != x)
		{
			badFlag=true;
		}			
	} 

	if(badFlag)
	{
		std::cout<<"FAILED: removeFront does not work as expected. \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeFront performes to expectations. \n";
	}


	//I'm just going to refresh this list
	refreshLinkedList();


	std::cout<<"7) Does addBack work? ";
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
			//std::cout<<"BAD THING: Vector not accurately reflecting addFront requirements " << listResults[x] << "\n";
			badFlag=true;
		}

	}

	if(badFlag==true)
	{
		std::cout<<"FAILED: addBack is broken, and does not store values properly.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: addBack adds values properly. \n";
	}






	std::cout<<"8) Checking if size incremented the correct number after adding 10 entries to back: ";
	m_testCount++;
	if( (m_list1->size() - initialSize) == 10)
	{
		std::cout<<"PASSED: Size has incremented correctly. \n";
	}
	else
	{
		std::cout<<"FAILED: Size has not incremented correctly. \n";
		m_bugCount++;
	}


	



	std::cout<<"9) Does removeBack remove values correctly (in conjunction with addBack)? ";
	m_testCount++;
	//reset badFlag
	badFlag=false;
	for(int x=0; x<5; x++)
	{
		//std::cout<<listResults[9-x] <<" ";
		if(m_list1->removeBack())
		{
			//std::cout<<"Value removed. \n";
		}
		else
		{
			//std::cout<<"function claims value not removed. \n";
		}
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
		std::cout<<"FAILED: removeBack does not work as expected. \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack performes to expectations. \n";
	}


	//refresh the list
	refreshLinkedList();





	std::cout<<"10) Remove Back after using (working) addFront? ";
	//populate list using known working method
	for (int x=0; x<10; x++)
	{
		m_list1->addFront(x);
	}
	m_testCount++;
	badFlag=false;
	for(int x=0; x<5 ; x++)
	{
		//this bool does nothing, just used as a receptacle
		//for the return value
		bool tosser=m_list1->removeBack();
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
		std::cout<<"FAILED: removeBack does not perform to expectations.\n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack works as expected. \n";
	}




	//refresh again
	refreshLinkedList();


	std::cout<<"11) Does removeBack return false on an empty list? ";
	m_testCount++;
	if(m_list1->removeBack())
	{
		std::cout<<"FAILED: removeBack returned true on an empty list! \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack returned false on an empty list. \n";
	}
	



	//refresh again
	refreshLinkedList();


	std::cout<<"12) Does removeFront return false on an empty list? ";
	m_testCount++;
	if(m_list1->removeFront())
	{
		std::cout<<"FAILED: removeFront returned true on an empty list! \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeFront returned false on an empty list. \n";
	}





	//and refresh again
	refreshLinkedList();




	std::cout<<"13) Does search(value) work? ";
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
		std::cout<<"FAILED: search could not find one or more value \n";
		m_bugCount++;
	}
	else
	{
		std::cout<<"PASSED: search found all expected values. \n";
	}


	std::cout<<"SCORE: " << (m_testCount - m_bugCount) << "/" << m_testCount <<"\n";

	delete(m_list1);
	return;
}

void Test::refreshLinkedList()
{
	delete m_list1;
	m_list1 = new LinkedList<int>();
	return;
}
