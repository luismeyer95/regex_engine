#include "../includes/PatternValidation.hpp"

PatternValidation::PatternValidation(const std::string& pattern)
	: pattern(pattern), index(0)
{
	alphabet.reserve(127);
	for (auto i = 0; i < 127; ++i)
		alphabet.push_back((char)i);

	axiom();
}

PatternValidation::~PatternValidation() {}

void PatternValidation::axiom()
{
	if (peek() == '^')
		next();
	expr();
	if (peek() == '$')
		next();
}

void PatternValidation::expr()
{
	term();

	if (peek() == '|')
	{
		eat('|');
		expr();
	}
}

void PatternValidation::term()
{
	factor();
	if (more())
	{
		if (peek() != '|' && peek() != ')' && peek() != '$')
			term();
	}
}

void PatternValidation::factor()
{
	atom();
	if (more() && std::string("?*+{").find(peek()) != std::string::npos)
		modifier();
}

void PatternValidation::modifier()
{
	char c = next();
	switch (c)
	{
		case '*': break;
		case '?': break;
		case '+': break;
		case '{': {
			quantify();
			eat('}');
			break;
		}
		default: break;
	}
}

void PatternValidation::quantify()
{
	std::string smin;
	while (std::isdigit(peek()))
		smin.append(1, next());
	int min = smin.empty() ? 0 : std::stoi(smin);
	if (peek() == '}')
		return;

	eat(',');

	std::string smax;
	while (std::isdigit(peek()))
		smax.append(1, next());
	int max = smax.empty() ? -1 : std::stoi(smax);

	if (max == -1)
		return;
	else if (max < 0 || min < 0 || max < min)
		throw std::runtime_error("Regex: Invalid quantifier range");
}

void PatternValidation::atom()
{
	if (peek() == '(')
	{
		eat('(');
		expr();
		eat(')');
	}
	else if (peek() == '[')
	{
		eat('[');
		bracket();
		eat(']');
	}
	else
		charset();
}

void	PatternValidation::bracket()
{
	if (peek() == '^')
		return (next(), setof());
	else
		return setof();
}

void PatternValidation::setof()
{
	while (peek() && peek() != ']')
		next();

	if (!peek())
		throw std::runtime_error("Regex: Missing end bracket token");
}

void PatternValidation::charset()
{
	if (peek() == '\\')
	{
		eat('\\');
		// any char
		if (!more())
			throw std::runtime_error("Regex: Invalid escape sequence");
		next();
	}
	else
	{
		if (std::string("?*+").find(peek()) != std::string::npos)
			throw std::runtime_error("Regex: Misused meta-character token");
		next();
	}
}

char PatternValidation::peek()
{
	return pattern[index];
}

char PatternValidation::next()
{
	return pattern[index++];
}

void PatternValidation::eat(char token)
{
	if (peek() != token)
	{
		std::stringstream s;
		s << "Regex: Invalid token `" << peek() << "`"; 
		throw std::runtime_error(s.str());
	}
	++index;
}

bool PatternValidation::more()
{
	return index < pattern.size();
}
