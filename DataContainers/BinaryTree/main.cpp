#include <iostream>
using namespace std;

#define tab '\t'

class Tree
{
	class Element
	{
		int data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->data = data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			//cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			//cout << "EDestructor:\t" << this << endl;
		}
		bool isLeaf() const
		{
			return pLeft == pRight;
		}
		friend class Tree;
	} *Root; // Указатель на корневой элемент
public:
	const Element* get_root() const
	{
		return Root;
	}
	Element* get_root()
	{
		return Root;
	}
	Tree() : Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) : Tree()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			insert(*it);
		}
		cout << "ILConstructor:\t" << this << endl;
	}
	Tree(const Tree& other) : Tree()
	{
		copy(other.Root);
		cout << "CConstructor:\t" << this << endl;
	}
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}
	Tree& operator = (const Tree& other)
	{
		if (this == &other) return *this;
		clear();
		copy(other.Root);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	void insert(const int& data)
	{
		insert(data, Root);
	}
	void erase(const int& data)
	{
		erase(data, Root);
	}
	void print()
	{
		print(Root);
	}
	void clear()
	{
		clear(Root);
	}
	int minValue()
	{
		return minValue(Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int size()
	{
		return size(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	double avg()
	{
		return avg(Root);
	}
private:
	void insert(const int& data, Element* root) // Здесь Element* root - это указатель на ветку (поддерево)
	{
		if (this->Root == nullptr) // Если дерево пустое (проверяем основной корень дерева), то инициализируем первый элемент
		{
			this->Root = new Element(data);
		}
		if (root == nullptr) return; // Условие выхода из рекурсии - проверяем передаваемый параметр (корень поддерева)
		if (data < root->data)
		{
			if (root->pLeft == nullptr) // Если текущий элемент (root) не имеет левого потомка...
			{
				root->pLeft = new Element(data); // ...создаём его.
			}
			else // В противном случае...
			{
				insert(data, root->pLeft); // ...идём дальше.
			}
		}
		if (data > root->data)
		{
			if (root->pRight) insert(data, root->pRight);
			else root->pRight = new Element(data);
		}
	}
	void print(Element* root)
	{
		if (root == nullptr) return;
		print(root->pLeft);
		cout << root << tab << root->data << endl;
		print(root->pRight);
	}
	void copy(Element* root)
	{
		if (root == nullptr) return;
		insert(root->data);
		copy(root->pLeft);
		copy(root->pRight);
	}
	void clear(Element*& root)
	{
		if (root == nullptr) return;
		clear(root->pLeft);
		clear(root->pRight);
		delete root;
		root = nullptr;
	}
	int minValue(Element* root)
	{
		return root->pLeft ? minValue(root->pLeft) : root->data;
	}
	int maxValue(Element* root)
	{
		return root->pRight ? maxValue(root->pRight) : root->data;
	}
	int size(Element* root)
	{
		return root ? size(root->pLeft) + size(root->pRight) + 1 : 0;
	}
	int sum(Element* root)
	{
		return root ? sum(root->pLeft) + sum(root->pRight) + root->data : 0;
	}
	double avg(Element* root)
	{
		return (double)sum(root) / size(root);
	}
	void erase(const int& data, Element*& root)
	{
		if (root == nullptr) return;
		erase(data, root->pLeft);
		erase(data, root->pRight);
		if (data == root->data)
		{
			if (root->isLeaf())
			{
				delete root;
				root = nullptr;
			}
			else
			{
				if (root->pLeft)
				{
					root->data = maxValue(root->pLeft);
					erase(maxValue(root->pLeft), root->pLeft);
				}
				else
				{
					root->data = minValue(root->pRight);
					erase(minValue(root->pRight), root->pRight);
				}
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Tree tree = {50, 25, 16, 32, 64, 55, 77};
	Tree tree2 = tree;
	Tree tree3;
	tree3 = tree;
	tree.print();
	cout << "*******************************\n";
	tree2.print();
	cout << "*******************************\n";
	tree3.print();
	cout << endl;
	/*cout << "Minimal value: " << tree.minValue() << endl;
	cout << "Maximal value: " << tree.maxValue() << endl;
	cout << "Size of the tree: " << tree.size() << endl;
	cout << "Sum of elements: " << tree.sum() << endl;
	cout << "Average: " << tree.avg() << endl;
	int value;
	cout << "Enter value to erase: "; cin >> value;
	tree.erase(value);
	tree.print();
	tree.clear();
	tree.print();*/
}