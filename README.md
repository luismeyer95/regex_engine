# regex_engine

A simplified regex engine made in C++, inspired from Denis Kyashif's implementation (https://deniskyashif.com/2019/02/17/implementing-a-regular-expression-engine/). Builds a non-deterministic finite automaton (NFA) off of an input regex pattern using recursive-descent parsing and matches strings by traversing it.
Note that this is a learning project and was not built with performance and memory-efficiency in mind.

## Compilation (Unix/MAC)

Compile the library using `make`:
```
$ make libregex.a
```

Include the `regex.hpp` header in your source code, compile and link with `libregex.a`.
Using the example `main.cpp` of this repo:

```
$ clang++ main.cpp libregex.a
```

This program takes the regex pattern as first argument and the string to match as second
```
$ ./a.out 'bc*d' abcccde
Match: yes
String matched: "bcccd"
```

## Usage

```
//	Instantiate a regex object with a pattern as argument

regex rgx(<pattern>);

// 	A call to the member function `match()` with a string as argument will match that string 
//	against the pattern and return the matched substring (if any).
// 	Its return type `regex::match_result` contains a bool `success` that is true if there is
// 	a match and a string `matched` that will contain the matched substring.

regex::match_result res = rgx.match(<string_to_match>);
if (res.success)
	std::cout << res.matched << std::end;

//	A call to the member function `groupmatch()` with a string as argument will match that 
//	string against the pattern and return the set of captures (if any).
//	Its return type `regex::groupmatch_result` contains a bool `success` that is true if 
//	there is a match and a vector of strings `matched` that will contain the set of captures,
//	starting with the whole matched substring

regex::groupmatch_result groupres = rgx.groupmatch(<string_to_match>)
if (groupres.success)
	for (auto& capture : groupres.matched)
		std::cout << capture << std::endl;

```

## Supported features

* Alternation (`|`)
* Anchors (`^`, `$`)
* Any character (`.`)
* Digit (`\d`) and whitespace (`\s`)
* Basic character classes (ex: `[^abc]`, `[A-Fa-f]`)
* Quantifiers (`*`, `?`, `+`, `{}`)
* Capturing and non-capturing groups (`(.+)`, `(?:.+)`)
* Escaping
