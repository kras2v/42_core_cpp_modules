#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <fstream>
#include <iostream>

class Replacer
{
	private:
		size_t			_newLineCounter;
		std::ifstream	_ifstream;
		std::ofstream	_ofstream;
		std::string		_filename;
		std::string		_stringToReplace;
		std::string		_replaceWith;
		int				open_fstreams();
		size_t 			character_count( std::string s, char c );
		void			splitLineToReplace( std::string *string );
		void			handleMultipleLineString(
							std::string &line,
							std::string *strings
						);

	public:
		Replacer(
			std::string filename,
			std::string s1,
			std::string s2
		);
		~Replacer();
		int				search_and_replace();
};

#endif