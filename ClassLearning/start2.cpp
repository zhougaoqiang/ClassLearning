#include "pch.h"
#include "Worker0.h"
#include "workermi.h"
#include "stacktp.h"
#include "arraytp.h"
#include "tv.h"
#include <iostream>
void stacktem();
void twod();    //making a 2-D array


int main()
{
	//worktest();
	//workmi();
	//stacktem();
	//twod();
	use_tv();
}

void stacktem() {
	Stack<std::string>st; //create an empty stack
	char ch;
	std::string po;

	cout << "Please enter A to add a purchase order, \n"
		<< "P to process a PO, or Q to quit. \n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << "\a";
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full \n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
				break;
			}
		}

		cout << "Please enter A to add a purchase oreder, \n"
			<< "P to process a PO, or Q to quit. \n";
	}
	cout << "Bye\n";
}
void twod()
{
	using std::cout;
	using std::endl;

	ArrayTP<int, 10> sums;
	ArrayTP<double, 10>aves;
	ArrayTP<ArrayTP<int, 8>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 7; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 9;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 7; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}

	cout << "Done.\n";
}