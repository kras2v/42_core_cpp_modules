#include "Replacer.hpp"

Replacer::Replacer(
	std::string filename,
	std::string s1,
	std::string s2
) :
	_filename(filename),
	_stringToReplace(s1),
	_replaceWith(s2)
{
	#ifdef DEBUG
		std::cout << "Replacer constructor" << std::endl;
	#endif
}

Replacer::~Replacer()
{
	#ifdef DEBUG
		std::cout << "Replacer destructor" << std::endl;
	#endif
}

int Replacer::open_fstreams()
{
	this->_ifstream.open(this->_filename.c_str(), std::ifstream::in);
	if (this->_ifstream.fail())
	{
		std::cerr << "Cannot open file " << this->_filename << std::endl;
		return (-1);
	}
	const std::string filename_replace = this->_filename + ".replace";
	this->_ofstream.open(filename_replace.c_str(), std::ofstream::out);
	if (this->_ofstream.fail())
	{
		std::cerr << "Cannot open file " << filename_replace << std::endl;
		return (-1);
	}
	return (0);
}

size_t  Replacer::character_count(std::string s, char c)
{
	size_t char_counter = 0;
	size_t char_pos = 0;
	while ((char_pos = s.find(c, char_pos)) != std::string::npos)
	{
		char_counter++;
		char_pos++;
	}
	return (char_counter);
}

void Replacer::splitLineToReplace(std::string *strings)
{
	if (this->_newLineCounter > 1)
	{
		size_t start = 0;
		for (size_t i = 0; i < this->_newLineCounter; i++)
		{
			size_t end  = this->_stringToReplace.find('\n', start);
			if (end == std::string::npos) {
				end = this->_stringToReplace.size() - 1;
			}
			strings[i].append(this->_stringToReplace, start, end - start);
			start = end + 1;
		}
	}
}

void Replacer::handleMultipleLineString(std::string &line, std::string *strings)
{
	std::string tmp;

	if (this->_newLineCounter > 1)
	{
		for (size_t i = 0; i < this->_newLineCounter; i++)
		{
			if (line.find_last_of(strings[i]) == line.size() - strings[i].size())
			{
				line.append("\n");
				if (!getline(this->_ifstream, tmp))
				{
					break;
				}
				line.append(tmp);
			}
			else
			{
				break;
			}
		}
	}
}

int  Replacer::search_and_replace()
{
	if (this->open_fstreams()) {
		return (1);
	}
	this->_newLineCounter = character_count(this->_stringToReplace, '\n') + 1;
	std::string splitedLineToReplace[this->_newLineCounter];
	splitLineToReplace(splitedLineToReplace);
	while (!this->_ifstream.eof())
	{
		size_t start = 0, end = 0;
		std::string line, buffer;
		if (!getline(this->_ifstream, line)) {
			break;
		}
		handleMultipleLineString(line, splitedLineToReplace);
		while (this->_stringToReplace.size() > 0
			&& (end = line.find(this->_stringToReplace, start)) != std::string::npos)
		{
			buffer.append(line, start, end - start);
			buffer.append(this->_replaceWith);
			start = end + this->_stringToReplace.size();
		}
		buffer.append(line, start);
		if (!this->_ifstream.eof()){
			buffer += "\n";
		}
		this->_ofstream << buffer;
	}
	return (0);
}
