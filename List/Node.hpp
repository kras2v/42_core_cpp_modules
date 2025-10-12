#ifndef NODE_HPP
# define NODE_HPP

# include <list>

template <typename T>
class Node
{
	private:
		T		  _content;
		Node <T>  *_next;
		Node <T>  *_prev;

	public:
		Node() = delete;
		Node(const Node &other);
		Node &operator=(const Node &other);
		~Node();

		Node(T content);

		T				&getContent();
		static Node<T>	*newNode(T content);
		Node<T>			*getNextNode() const;
		Node<T>			*getPrevNode() const;
		void 			setNextNode(Node<T> *node);
		void 			setPrevNode(Node<T> *node);
};

#include "Node.tpp"

#endif /* NODE_HPP */