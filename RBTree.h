#pragma once

#include <iostream.>
#include <iomanip>
using namespace std;


enum RBTColor { Black, Red };

template<class KeyType>
struct  RBTNode
{
	KeyType key;
	RBTColor color;
	RBTNode<KeyType>* left;
	RBTNode<KeyType>* right;
	RBTNode<KeyType>* parent;
	RBTNode(KeyType k, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
		key(k), color(c), parent(p), left(l), right(r) { };
};

template<class T>
class  RBTree
{
public:
	RBTree();
	~RBTree();

	void insert(T key);    // Вставляем узел, ключ это значение ключа, внешний интерфейс
	void remove(T key); // Удалить ключевой узел
	RBTNode<T>* search(T key);
	void print();
	void preOrder();    // Предзаказ обхода печати красного черного дерева
	void inOrder();    // Обход последовательности
	void postOrder();    // пост-заказ обхода		



private:
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);// левая рука
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);// правая рука

	void insert(RBTNode<T>*& root, RBTNode<T>* node);// Вставляем узел, внутренний интерфейс
	void InsertFixUp(RBTNode<T>*& root, RBTNode<T>* node);
	void destory(RBTNode<T>*& node);

	void remove(RBTNode<T>*& root, RBTNode<T>* node);// Удалить узел как KEY
	void removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	RBTNode<T>* search(RBTNode<T>* node, T key) const;
	void print(RBTNode<T>* node)const;
	void preOrder(RBTNode<T>* tree)const;
	void inOrder(RBTNode<T>* tree)const;
	void postOrder(RBTNode<T>* tree)const;
private:
	RBTNode<T>* root;
};

