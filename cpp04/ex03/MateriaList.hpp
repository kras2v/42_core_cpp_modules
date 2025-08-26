
#ifndef MATERIALIST_HPP
# define MATERIALIST_HPP

# include "AMateria.hpp"
# include <iostream>
# include <iomanip>

typedef struct s_materia_node
{
	AMateria				*curr;
	struct s_materia_node	*next;
}	t_materia_node;

class MateriaList
{
	private:
		size_t			_currentSize;
		t_materia_node *_head;

	public:
		MateriaList ( );
		MateriaList ( AMateria *newNode );
		MateriaList ( const MateriaList &other );
		~MateriaList( );

		MateriaList&	operator=( const MateriaList &other );
		t_materia_node	*createNewNode( AMateria *curr );
		void			addBack( AMateria *next );
		t_materia_node	*getLast( ) const;
		t_materia_node	*getFirst( ) const;
		size_t			getSize() const;
		void			clear();
};

#endif
