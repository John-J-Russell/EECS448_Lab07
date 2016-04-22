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
	LinkedList<int>* list1 = new LinkedList<int>();
	int bugCount=0;
	int testCount=0;
	int initialSize=list1->size();
	/*
	std::cout<<"Is empty on creation: "<< list1->isEmpty() << "\n";
	std::cout<<"Size on creations via getSize: " << list1->size() <<"\n";

	std::cout<<"Starts with an entry? Remove front before doing anything else: ";

	try
	{
		std::cout<< list1->removeFront() << "\n";
	}
	catch(int e)
	{
		std::cout<< "either there was nothing there, or remove front is broken. \n";
	}

	std::cout<<"Remove back maybe? ";
	try
	{
		std::cout<< list1->removeBack();
	}
	catch(int e)
	{
		std::cout<< "either there was nothing there, or remove back is broken. \n";
	}

	list1->addFront(7);

	std::cout<<"\n Add an entry, check size and empty again \n";

	std::cout<<"Is empty after being given thing: "<< list1->isEmpty() << "\n";
	std::cout<<"size after having attempted removing one, and adding one" << list1->size() <<"\n";
	*/

	std::cout<<"1) Testing for size() on creation: ";
	testCount++;
	if(list1->size()!=0)
	{
		std::cout<<"FAILED: size does not return zero upon creation \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: size is zero upon creation \n";
	}





	std::cout<<"2) Testing isEmpty() on creation: ";
	testCount++;
	if(!list1->isEmpty())
	{
		std::cout<<"FAILED: isEmpty does not return true on creation \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: list is empty on creation \n";
	}





	std::cout<<"3)Does list actually start out empty? ";
	testCount++;
	std::vector<int> listResults = list1->toVector();
	if(listResults.size() != 0)
	{
		std::cout<<"FAILED: List is not empty upon creation \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: List is indeed empty upon creation \n";
	}





	std::cout<<"4) Does addFront work? ";
	testCount++;
	//Add 10 entries to list using addFront
	for(int x=0; x<10; x++)
	{
		list1->addFront(x);
	}
	//cast results to vector
	listResults=list1->toVector();
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
		std::cout<<"FAILED: addFront is broken, and does not store proper values \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: addFront appears to actually add to the list! \n";
	}






	std::cout<<"5) Checking if size incremented the correct number after adding 10 entries: ";
	testCount++;
	if( (list1->size() - initialSize) == 10)
	{
		std::cout<<"PASSED: Size has incremented correctly. \n";
	}
	else
	{
		std::cout<<"FAILED: Size has not incremented correctly. \n";
		bugCount++;
	}





	std::cout<<"SCORE: " << (testCount - bugCount) << "/" << testCount <<"\n";

	delete(list1);
	return;
}


