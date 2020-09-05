#include "includes/Regex.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
		return(1);
	
	try {
		std::cout << Regex(av[1]).match(av[2]) << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}