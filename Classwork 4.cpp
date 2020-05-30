
#include <iostream>
#include <fstream>
using namespace std;

class STACK
{
public:
	STACK();
	~STACK();
	void push(int d);
	int pop();
	void print();
	bool empty();
private:
	struct Node
	{
		int d;
		Node* next;
	};
	Node* top;
};
STACK::STACK() :top(NULL){}

void STACK::push(int d)
{
	Node* pv = new Node;
	pv->d = d;
	pv->next = top;
	top = pv;
}

int STACK::pop()
{
	if (empty() == true)
		return false;
	int temp = top->d;
	Node* pv = top;
	top = top->next;
	delete pv;
	return temp;
}

bool STACK::empty()
{
	if (top != NULL) return false;
	else return true;
}

void STACK::print()
{
	while (top)
	{
		cout << pop() << endl;
	}
}

void emptystack(STACK & stack);

int main()
{
	STACK TrainALL, train_one, train_two;
	ifstream file("C:\\Users\\VLADA\\Desktop\\train.txt");
	
	if (!file)
	{
		cout << "File not found" << endl;
		return 1;
	}
	while (!file.eof())
	{
		int pr;
		file >> pr;
		TrainALL.push(pr);
	}
	while(!TrainALL.empty())
	{
		int pr = TrainALL.pop();
		switch(pr)
		{
		case 1:
			train_one.push(pr);
			break;
		case 2:
			train_two.push(pr);
			break;

		}
	}
	train_one.print();
	train_two.print();

	/*int choise = _getch();

    switch(choise)
	{
		system("cls");
	}
	return 0;
	*/
}

void emptystack(STACK & stack)
{
	if (!stack.empty())
	{
		cout << "Stack isn't empty" << endl;
	}
}