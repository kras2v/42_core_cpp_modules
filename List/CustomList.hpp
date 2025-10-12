#ifndef CUSTOMLIST_HPP
# define CUSTOMLIST_HPP

# include "Node.hpp"
# include <iostream>

template <typename T>
class CustomList
{
	private:
		Node<T> *_head;

	public:
		CustomList();
		CustomList(const CustomList &other);
		CustomList &operator=(const CustomList &other);
		~CustomList();

		CustomList(Node <T> &head);

		void 		addBack(Node <T> &newNode);
		void 		addBack(const T &content);
		void 		addFront(Node <T> &newNode);
		void		addFront(const T &content);
		void 		clear();
		void		removeFront();
		void		removeBack();
		size_t		getSize() const;
		Node <T> *	getLastNode();
		Node <T> *	getHead() const;
		void		copy(const CustomList &other);
};

#include "CustomList.tpp"

#endif /* CUSTOMLIST_HPP */