#include "CustomList.hpp"

template <typename T>
CustomList<T>::CustomList() : _head(nullptr)
{
	#ifdef DEBUG
		std::cout << "CustomList default constructor" << std::endl;
	#endif
}

template <typename T>
CustomList<T>::~CustomList()
{
	#ifdef DEBUG
		std::cout << "CustomList destructor" << std::endl;
	#endif
	this->empty();
}

template <typename T>
CustomList<T>::CustomList(const CustomList &other) : _head(nullptr)
{
	#ifdef DEBUG
		std::cout << "CustomList copy constructor" << std::endl;
	#endif
	this->copy(other);
}

template <typename T>
CustomList<T>& CustomList<T>::operator=(const CustomList<T> &other)
{
	#ifdef DEBUG
		std::cout << "CustomList assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		empty();
		this->copy(other);
	}
	return *this;
}

template <typename T>
CustomList<T>::CustomList(Node <T> &head)
{
	#ifdef DEBUG
		std::cout << "CustomList parametrized constructor" << std::endl;
	#endif
	this->_head = &head;
}

template <typename T>
void CustomList<T>::copy(const CustomList<T> &other)
{
	Node <T> *currentOther = other.getHead();
	if (currentOther)
		this->_head = Node<T>::newNode(currentOther->getContent());

	Node <T> *currentThis = this->_head;
	currentOther = currentOther->getNextNode();
	while (currentOther != nullptr)
	{
		Node <T> * newCopy = Node<T>::newNode(currentOther->getContent());
		currentThis->setNextNode(newCopy);
		currentThis = currentThis->getNextNode();
		currentOther = currentOther->getNextNode();
	}
}

template <typename T>
Node <T> * CustomList<T>::getLastNode()
{
	Node<T> *current = this->_head;
	while (current->getNextNode() != nullptr)
	{
		current = current->getNextNode();
	}
	return current;
}

template <typename T>
size_t CustomList<T>::getSize() const
{
	Node<T> *current = this->_head;
	size_t size = 0;
	while (current && current != nullptr)
	{
		current = current->getNextNode();
		size++;
	}
	return size;
}

template <typename T>
Node <T> *CustomList<T>::getHead() const
{
	return this->_head;
}

template <typename T>
void CustomList<T>::addBack(Node <T> &newNode)
{
	Node<T> *newCopy = new Node<T>(newNode);
	if (this->_head == nullptr)
	{
		this->_head = newCopy;
		return ;
	}
	Node<T> *lastNode = getLastNode();
	lastNode->setNextNode(newCopy);
	newCopy->setPrevNode(lastNode);
}

template <typename T>
void CustomList<T>::addBack(const T& content)
{
	Node<T> *newCopy = new Node<T>(content);
	if (this->_head == nullptr)
	{
		this->_head = newCopy;
		return ;
	}
	Node<T> *lastNode = getLastNode();
	lastNode->setNextNode(newCopy);
	newCopy->setPrevNode(lastNode);
}

template <typename T>
void CustomList<T>::addFront(const T &content)
{
	Node<T> *newCopy = new Node<T>(content);
	if (this->_head == nullptr)
	{
		this->_head = newCopy;
		return ;
	}
	newCopy->setNextNode(this->_head);
	_head->setPrevNode(newCopy);
	this->_head = newCopy;
}

template <typename T>
void CustomList<T>::addFront(Node <T> &newNode)
{
	Node<T> *newCopy = new Node<T>(newNode);
	if (this->_head == nullptr)
	{
		this->_head = newCopy;
		return ;
	}
	newCopy->setNextNode(this->_head);
	_head->setPrevNode(newCopy);
	this->_head = newCopy;
}

template <typename T>
void CustomList<T>::empty()
{
	Node<T> *current = this->_head;
	while (current != nullptr)
	{
		Node<T> *next = current->getNextNode();
		delete current;
		current = next;
	}
}

template <typename T>
void CustomList<T>::removeFront()
{
	if (this->getHead() == nullptr)
		return;

	Node <T> *oldHead = this->_head;
	this->_head = oldHead->getNextNode();
	delete oldHead;
}

template <typename T>
void CustomList<T>::removeBack()
{
	if (this->getHead() == nullptr)
		return;

	if (this->_head->getNextNode() == nullptr)
	{
		delete this->_head;
		this->_head = nullptr;
		return;
	}

	Node <T> *current = this->_head;
	while (current->getNextNode() && current->getNextNode()->getNextNode())
	{
		current = current->getNextNode();
	}
	Node <T> *last = current->getNextNode();
	current->setNextNode(nullptr);
	delete last;
}

