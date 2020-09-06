#include "includes/Regex.hpp"

// ex: match an absolute path of lowercase characters only
// $ ./a.out '^(/[a-z]*)+/?$' '/yo/ya/'

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "usage: " << av[0] << " <pattern> <string_to_match>" << std::endl;
		return(1);
	}
	
	try {
		Regex rgx(av[1]);
		std::pair<bool, std::string> p = rgx.match(av[2]);
		std::cout << "Match: " << (p.first ? "yes" : "no") << std::endl;
		if (p.first)
			std::cout << "String matched: \"" << p.second << "\"" << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}