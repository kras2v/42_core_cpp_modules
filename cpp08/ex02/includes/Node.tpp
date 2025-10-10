#include "Node.hpp"

template <typename T>
Node<T>::Node(T content) : _content(content), _next(nullptr), _prev(nullptr)
{
	#ifdef DEBUG
		std::cout << "CustomList parametrized constructor" << std::endl;
	#endif
}

template <typename T>
Node<T>::Node(const Node &other) : _content(other.getContent()), _next(nullptr), _prev(nullptr)
{
	#ifdef DEBUG
		std::cout << "CustomList copy constructor" << std::endl;
	#endif
}

template <typename T>
Node<T> & Node<T>::operator=(const Node<T> &other)
{
	#ifdef DEBUG
		std::cout << "CustomList assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		this->_content = other._content;
		this->_next = nullptr;
		this->_prev = nullptr;
	}
	return *this;
}

template <typename T>
Node<T>::~Node()
{
	#ifdef DEBUG
		std::cout << "CustomList destructor" << std::endl;
	#endif
}

template <typename T>
T &Node<T>::getContent()
{
	return this->_content;
}

template <typename T>
Node<T> *Node<T>::newNode(T content)
{
	Node<T> *newNode = new Node<T>(content);
	return newNode;
}

template <typename T>
Node<T> *Node<T>::getNextNode() const
{
	return this->_next;
}

template <typename T>
Node<T> *Node<T>::getPrevNode() const
{
	return this->_prev;
}

template <typename T>
void Node<T>::setNextNode(Node<T> *node)
{
	this->_next = node;
}

template <typename T>
void Node<T>::setPrevNode(Node<T> *node)
{
	this->_prev = node;
}