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
	//tracks bug total
	int bugCount=0;
	//tracks test total
	int testCount=0;
	//used for the purpose of checking size incrementation
	int initialSize=list1->size();
	

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





	std::cout<<"3) Does list actually start out empty? ";
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
		std::cout<<"FAILED: addFront is broken, and does not store values properly.\n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: addFront adds values properly. \n";
	}






	std::cout<<"5) Checking if size incremented the correct number after adding 10 entries to front: ";
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




	std::cout<<"6) Does removeFront remove values correctly? ";
	testCount++;
	//reset badFlag
	badFlag=false;
	for(int x=0; x<5; x++)
	{
		if(list1->removeFront())
		{
			//std::cout<<"Value removed. \n";
		}
		else
		{
			//std::cout<<"function claims value not removed. \n";
		}
	}
	listResults=list1->toVector();

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
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeFront performes to expectations. \n";
	}


	//I'm just going to refresh this list
	delete list1;
	list1 = new LinkedList<int>();


	std::cout<<"7) Does addBack work? ";
	testCount++;
	//Add 10 entries to list using addFront
	for(int x=0; x<10; x++)
	{
		list1->addBack(x);
	}
	//cast results to vector
	listResults=list1->toVector();
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
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: addBack adds values properly. \n";
	}






	std::cout<<"8) Checking if size incremented the correct number after adding 10 entries to back: ";
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


	



	std::cout<<"9) Does removeBack remove values correctly (in conjunction with addBack)? ";
	testCount++;
	//reset badFlag
	badFlag=false;
	for(int x=0; x<5; x++)
	{
		//std::cout<<listResults[9-x] <<" ";
		if(list1->removeBack())
		{
			//std::cout<<"Value removed. \n";
		}
		else
		{
			//std::cout<<"function claims value not removed. \n";
		}
	}
	listResults=list1->toVector();

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
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack performes to expectations. \n";
	}



	delete list1;
	list1 = new LinkedList<int>;






	std::cout<<"10) Remove Back after using (working) addFront? ";
	//populate list using known working method
	for (int x=0; x<10; x++)
	{
		list1->addFront(x);
	}
	testCount++;
	badFlag=false;
	for(int x=0; x<5 ; x++)
	{
		bool tosser=list1->removeBack();
	}

	listResults=list1->toVector();

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
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack works as expected. \n";
	}




	//refresh again
	delete list1;
	list1 = new LinkedList<int>;



	std::cout<<"11) Does removeBack return false on an empty list? ";
	testCount++;
	if(list1->removeBack())
	{
		std::cout<<"FAILED: removeBack returned true on an empty list! \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeBack returned false on an empty list. \n";
	}
	



	//refresh again
	delete list1;
	list1 = new LinkedList<int>;



	std::cout<<"12) Does removeFront return false on an empty list? ";
	testCount++;
	if(list1->removeFront())
	{
		std::cout<<"FAILED: removeFront returned true on an empty list! \n";
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: removeFront returned false on an empty list. \n";
	}





	//and refresh again
	delete list1;
	list1 = new LinkedList<int>;




	std::cout<<"13) Does search(value) work? ";
	testCount++;
	badFlag=false;
	for(int x=0; x<10; x++)
	{
		list1->addFront(x);
	}
	for(int x=0; x<10; x++)
	{
		if(list1->search(x))
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
		bugCount++;
	}
	else
	{
		std::cout<<"PASSED: search found all expected values. \n";
	}


	std::cout<<"SCORE: " << (testCount - bugCount) << "/" << testCount <<"\n";

	delete(list1);
	return;
}


