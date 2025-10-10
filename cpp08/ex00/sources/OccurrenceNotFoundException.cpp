#include "OccurrenceNotFoundException.hpp"

const char *OccurrenceNotFoundException::what() const noexcept
{
	return "Occurrence is not found!";
}