#include "MateriaList.hpp"

MateriaList::MateriaList ( ) : _currentSize(0), _head(nullptr)
{
	std::cout << "MateriaList default constructor" << std::endl;
}

MateriaList::MateriaList ( AMateria *newNode ) : _currentSize(0), _head(nullptr)
{
	std::cout << "MateriaList default constructor" << std::endl;
	if (newNode)
		addBack(newNode);
}

MateriaList::MateriaList ( const MateriaList &other )  : _currentSize(0), _head(nullptr)
{
	*this = other;
	std::cout << "MateriaList copy constructor" << std::endl;
}

MateriaList::~MateriaList( )
{
	std::cout << "MateriaList destructor" << std::endl;
	this->clear();
}

MateriaList& MateriaList::operator=(const MateriaList& other)
{
	if (this != &other)
	{
		this->clear();
		t_materia_node* tmp = other.getFirst();
		while (tmp)
		{
			this->addBack(tmp->curr->clone());
			tmp = tmp->next;
		}
	}

	std::cout << "MateriaList copy assignment operator" << std::endl;
	return *this;
}

t_materia_node *MateriaList::createNewNode( AMateria *curr )
{
	t_materia_node *newNode = new t_materia_node;
	newNode->curr = curr;
	newNode->next = nullptr;
	return (newNode);
}

void	MateriaList::addBack( AMateria *next )
{
	_currentSize++;
	if (this->_head == nullptr)
	{
		this->_head = createNewNode(next);
		return ;
	}
	t_materia_node *last = getLast();
	last->next = createNewNode(next);
}

t_materia_node	*MateriaList::getLast( ) const
{
	t_materia_node *last = this->_head;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	return (last);
}

t_materia_node	*MateriaList::getFirst( ) const
{
	return (this->_head);
}

size_t	MateriaList::getSize() const
{
	return (this->_currentSize);
}

void	MateriaList::clear()
{
	t_materia_node *curr = this->_head;
	while (curr)
	{
		t_materia_node *next = curr->next;
		if (curr && curr->curr)
		{
			delete curr->curr;
			curr->curr = nullptr;
			delete curr;
			curr = nullptr;
		}
		curr = next;
	}
	curr = nullptr;
}
