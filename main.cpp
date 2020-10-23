#include "includes/regex.hpp"

// ex: match a path segment of lowercase characters and underscores only
// $ ./main '^/[a-z_]*/?$' '/path_segment/'

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "usage: " << av[0] << " <pattern> <string_to_match>" << std::endl;
		return(1);
	}
	
	try {
		regex rgx(av[1]);
		auto res = rgx.groupmatch(av[2]);
		std::cout << "Match: " << (res.success ? "yes" : "no") << std::endl;
		if (res.success)
		{
			std::cout << "String matched: \"" << res.matched.at(0) << "\"\n\n";
			std::cout << "Capture groups:" << std::endl;
			for (size_t i = 0; i < res.matched.size(); ++i)
				std::cout << "[" << i << "]: \"" << res.matched.at(i) << "\"" << std::endl;
		}
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}