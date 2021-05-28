#include <iostream>
using namespace std;

#define tab '\t'
#define delim "****************************************************\n";

class List
{
	class Element
	{
		int data;
		Element* pPrev;
		Element* pNext;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
			this->pNext = pNext;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	};
	Element* Head;
	Element* Tail;
	unsigned int size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		while (Tail) pop_back();
		cout << "LDestructor:\t" << this << endl;
	}
	// *************** ADD ELEMENTS ******************************************
	void push_front(int data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(data);
			size++;
			return;
		}
		Element* New = new Element(data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(int data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(data);
			size++;
			return;
		}
		Element* New = new Element(data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;
	}
	void insert(int data, int index)
	{
		if (index < 0 || index > size) return;
		if (index == size)
		{
			push_back(data);
			return;
		}
		if (index == 0)
		{
			push_front(data);
			return;
		}
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		Element* New = new Element(data);
		New->pPrev = temp->pPrev;
		New->pNext = temp;
		temp->pPrev->pNext = New;
		temp->pPrev = New;
		size++;
	}
	// *************** REMOVE ELEMENTS **********************************
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index < 0 || index >= size) return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
		delete temp;
		size--;
	}
	// *************** METHODS ******************************************
	void print()
	{
		for (Element* temp = Head; temp; temp = temp->pNext)
		{
			cout << temp << tab << temp->pPrev << tab << temp->data << tab << temp->pNext << endl;
		}
		cout << "Number of elements in the list: " << size << endl;
	}
	void print_reverse()
	{
		for (Element* temp = Tail; temp; temp = temp->pPrev)
		{
			cout << temp << tab << temp->pPrev << tab << temp->data << tab << temp->pNext << endl;
		}
		cout << "Number of elements in the list: " << size << endl;
	}
};

int main()
{
	List list;
	int n;
	cout << "Enter size of the list: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	cout << delim;
	list.print_reverse();
	cout << delim;
	list.insert(77, n);
	list.print();
	cout << delim;
	list.print_reverse();
	cout << delim;
	list.erase(5);
	list.print();
	cout << delim;
	list.print_reverse();
}