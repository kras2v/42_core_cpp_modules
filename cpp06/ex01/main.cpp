#include "Serializer.hpp"

int main()
{
	try
	{
		Data *data_old = new Data("some randooooom data");
		std::cout << "Data address before serialization: " << data_old << std::endl;
		std::cout << "Data attributes: " << data_old->getName() << std::endl;

		uintptr_t data_addr = Serializer::serialize(data_old);
		std::cout << "Data serialized addres:  " << data_addr << std::endl;

		Data *data_new = Serializer::deserialize(data_addr);
		std::cout << "Data address after deserialization:  " << data_new << std::endl;
		std::cout << "Data attributes: " << data_new->getName() << std::endl;

		delete data_old;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}