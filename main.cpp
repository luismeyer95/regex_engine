#include "includes/Regex.hpp"

int main(int ac, char **av)
{
	Regex reg(av[1]);
	std::cout << reg.match(av[2]) << std::endl;
}