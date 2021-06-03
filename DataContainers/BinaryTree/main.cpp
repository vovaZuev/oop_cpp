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
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int data, Element* root) // Здесь Element* root - это указатель на ветку (поддерево)
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
			/*if (root->pRight == nullptr)
			{
				root->pRight = new Element(data);
			}
			else
			{
				insert(data, root->pRight);
			}*/
			if (root->pRight) insert(data, root->pRight);
			else root->pRight = new Element(data);
		}
	}
	void print(Element* root)
	{
		if (root == nullptr) return;
		print(root->pLeft);
		cout << root->data << tab;
		print(root->pRight);
	}
	void clear(Element* root)
	{
		if (root == nullptr) return;
		clear(root->pLeft);
		clear(root->pRight);
		delete root;
	}
	int minValue(Element* root)
	{
		/*if (root->pLeft == nullptr) return root->data;
		minValue(root->pLeft);*/
		return root->pLeft ? minValue(root->pLeft) : root->data;
	}
	int maxValue(Element* root)
	{
		/*if (root->pRight == nullptr) return root->data;
		maxValue(root->pRight);*/
		return root->pRight ? maxValue(root->pRight) : root->data;
	}
	int size(Element* root)
	{
		/*if (root == nullptr) return 0;
		else return size(root->pLeft) + size(root->pRight) + 1;*/
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
};

int main()
{
	setlocale(LC_ALL, "");
	int n; // Кол-во эл-тов дерева
	cout << "Введите количество элементов: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.get_root());
	}
	tree.print(tree.get_root());
	cout << endl;
	cout << "Minimal value: " << tree.minValue(tree.get_root()) << endl;
	cout << "Maximal value: " << tree.maxValue(tree.get_root()) << endl;
	cout << "Size of the tree: " << tree.size(tree.get_root()) << endl;
	cout << "Sum of elements: " << tree.sum(tree.get_root()) << endl;
	cout << "Average: " << tree.avg(tree.get_root()) << endl;
}