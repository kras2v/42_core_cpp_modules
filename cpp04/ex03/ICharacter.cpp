#include "ICharacter.hpp"

ICharacter::ICharacter( void ) = default;
ICharacter::ICharacter( const ICharacter &other ) = default;
ICharacter & ICharacter::operator=( const ICharacter &other) = default;

ICharacter::~ICharacter() { }

void		ICharacter:: use(int idx, ICharacter& target) { (void)idx; (void)target; }