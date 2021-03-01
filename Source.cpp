#include <iostream>
#include <string>
using namespace std;

void groceryList(int groceries[], int size)               // Uses: string Library,  -Asks User for the grocies so that it'll be placed into a list   //string arr replaced with int
{
	cout << "                   Grocery Organizer\n";
	cout << "Type list of groceries below" << endl;

	for (int i = 0; i < size; ++i)                             // for loop used to obtain groceries of user up to 10
	{
		cin >> groceries[i];
	}
}

/*void bubbleSort(string input[], int length)                     //Uses: string Library,  -The function sort does what the name implies, sort in the shell sort method
{
	int i = 0, //represents the beginning variable in the first for loop.
		j = 0,  //represents the beginning variable in the second for loop.
		x = 0;  //represents the counter utlized in the print function.
	string temp;

	for (i = 0
; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (input[i].compare(input[j]) > 0)       // compares first char of a string between strings
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

} 
*/

void merge(int list[],int a,int m,int l)  //string arr replaced with int
{
	int mergedSize = l - a + 1,
		mergePos = 0,
		leftPos = 0,
		rightPos = 0;
	int *mergedNumbers = new int[mergedSize];  //string arr replaced with int


	leftPos = a;
	rightPos = m + 1;

	while (leftPos <= m && rightPos <= l)
	{
		//if (list[leftPos].compare(list[rightPos]) <= 0)      //Exception thrown here
		if(list[leftPos]<=list[rightPos])
		{
			mergedNumbers[mergePos] = list[leftPos];
			++leftPos;
		}
		else
		{
			mergedNumbers[mergePos] = list[rightPos];
			++rightPos;
		}
		++mergePos;
	}


	while (leftPos <= m)
	{
		mergedNumbers[mergePos] = list[leftPos];
		++leftPos;
		++mergePos;
	}


	while (rightPos <= l)
	{
		mergedNumbers[mergePos] = list[rightPos];
		++rightPos;
		++mergePos;
	}


	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		list[a + mergePos] = mergedNumbers[mergePos];
	}
}

void mergeSort(int input[], int i, int length)  //string arr replaced with int
{
	int j = 0;
	if (i < length)
	{
		j = (i + length)/2;

		mergeSort(input, i, j);
		mergeSort(input, j+1, length);

		merge(input, i, j, length);
	}


}

void print(int List[], int amount)         //Prints the program's before and after results
{
	cout << "List before: ";                         //Before results
	for (int i = 0; i < amount; ++i)
	{
		cout << List[i] << " ";
	}

	//bubbleSort(List, amount);                        // calls sorting function

	/*cout << "\nList after: ";                        //After results
	for (int i = 0; i < amount; ++i)
	{
		cout << List[i] << " ";
	}*/
}

int main()													//Uses: string Library,  -Main function that contains all the functions 
{
	const int listSize = 5;
	//string list[listSize];
	int list[listSize];
	int v = 0;
	groceryList(list, listSize);
	print(list, listSize);
	
	mergeSort(list, v, listSize);

	cout << "List after: ";                        
	for (int i = 0; i < listSize; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
	
	return 0;
}
