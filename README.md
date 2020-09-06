# regex_engine

A simplified regex engine made in C++, heavily inspired from Denis Kyashif's implementation (https://deniskyashif.com/2019/02/17/implementing-a-regular-expression-engine/). Builds a non-deterministic finite automaton (NFA) off of an input regex pattern using recursive-descent parsing and matches strings by traversing it.

## Usage

Compile the library using `make`:
```
$ make
```

Include the `Regex.hpp` header in your source code, compile and link with `libregex.a`.
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

## Supported features

* Anchors (`^`, `$`)
* Any character (`.`)
* Quantifiers (`*`, `?`, `+`, `{}`)
* Basic character classes (ex: `[abc]`, `[A-Z]`, `[^0-9]`)
* Parenthesis
* Escaping
