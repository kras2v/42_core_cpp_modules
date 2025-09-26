#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base * generate(void)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> instanceNumber(1, 3);

	switch (instanceNumber(gen))
	{
		case 1:
			return new A();
			break;
		case 2:
			return new B();
			break;
		case 3:
			return new C();
			break;
		default:
			break;
	}
	return (nullptr);
}

void identify(Base* p)
{
	char type = 'A';
	bool isFind = false;
	for (size_t i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0:
			{
				A *original = dynamic_cast<A *>(p);
				isFind = original != nullptr;
				break;
			}
			case 1:
			{
				B *original = dynamic_cast<B *>(p);
				isFind = original != nullptr;
				break;
			}
			case 2:
			{
				C *original = dynamic_cast<C *>(p);
				isFind = original != nullptr;
				break;
			}
			default:
				break;
		}
		if (isFind)
		{
			std::cout << "Type: " << static_cast<char>(type + i) << std::endl;
			return ;
		}
	}
}

void identify(Base& p)
{
	char type = 'A';
	for (size_t i = 0; i < 3; i++)
	{
		try
		{
			switch (i)
			{
				case 0:
				{
					A original = dynamic_cast<A&>(p);
					break;
				}
				case 1:
				{
					B original = dynamic_cast<B&>(p);
					break;
				}
				case 2:
				{
					C original = dynamic_cast<C&>(p);
					break;
				}
				default:
					break;
			}
			std::cout << "Type: " << static_cast<char>(type + i) << std::endl;
			return ;
		}
		catch(const std::exception& e) { }
	}
}

int main()
{
	size_t amount = 5;
	Base *bases[amount];
	for (size_t i = 0; i < amount; i++)
	{
		bases[i] = generate();
	}

	std::cout << "The actual type of the object referenced by p:" << std::endl;
	for (size_t i = 0; i < amount; i++)
	{
		identify(*bases[i]);
	}

	std::cout << "The actual type of the object object pointed by p:" << std::endl;
	for (size_t i = 0; i < amount; i++)
	{
		identify(bases[i]);
	}

	for (size_t i = 0; i < amount; i++)
	{
		delete bases[i];
	}
	return 0;
}
