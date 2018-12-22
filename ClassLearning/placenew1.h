//placenew1.cpp -- new, placement new , no delete


#include "pch.h"
#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting {
private:
	std::string words;
	int number;
public:
	JustTesting(const std::string & s = "Just Testing", int n = 0)
	{
		words = s; number = n; std::cout << words << " constructed\n";
	}
	~JustTesting()
	{
		std::cout << words << "detoryed\n";
	}
	void show() const
	{
		std::cout << words << ", " << number << endl;
	}
};

void placenew1();
void placenew2();

void placenew1() {
	char * buffer = new char[BUF];	//get a block of memory

	JustTesting *pc1, *pc2;

	pc1 = new (buffer) JustTesting;  //place object in buffer
	pc2 = new JustTesting("Heap1", 20); //place object on heap

	cout << "Memory block addresses: \n" << "buffer: "
		<< (void *)buffer << "    heap:" << pc2 << endl;
	cout << "Memory contents: \n";
	cout << pc1 << ": ";
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();

	JustTesting *pc3, *pc4;
	pc3 = new (buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents: \n";
	cout << pc3 << ": ";
	pc3->show();
	cout << pc4 << ": ";
	pc4->show();

	delete pc2;   //free heap1
	delete pc4;		//free heap2
	delete[] buffer;    //free buffer
	cout << "Done\n";
}
void placenew2() {
	char * buffer = new char[BUF];	//get a block of memory

	JustTesting *pc1, *pc2;

	pc1 = new (buffer) JustTesting;  //place object in buffer
	pc2 = new JustTesting("Heap1", 20); //place object on heap

	cout << "Memory block addresses: \n" << "buffer: "
		<< (void *)buffer << "    heap:" << pc2 << endl;
	cout << "Memory contents: \n";
	cout << pc1 << ": ";
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();

	JustTesting *pc3, *pc4;

	//fix placement new location;
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents: \n";
	cout << pc3 << ": ";
	pc3->show();
	cout << pc4 << ": ";
	pc4->show();

	delete pc2;   //free heap1
	delete pc4;		//free heap2

	//explicitly destory placement new objects ��ȷ�����ٷ����¶���
	pc3->~JustTesting();   //destory object pointed to by pc3
	pc1->~JustTesting();	//destory object pointed to by pc1
	delete []buffer;		//free buffer
	cout << "Done\n";
}
