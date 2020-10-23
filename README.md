# regex_engine

A simplified regex engine made in C++, inspired from Denis Kyashif's implementation (https://deniskyashif.com/2019/02/17/implementing-a-regular-expression-engine/). Builds a non-deterministic finite automaton (NFA) off of an input regex pattern using recursive-descent parsing and matches strings by traversing it.
Note that this is a learning project and was not built with performance and memory-efficiency in mind.

## Usage

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

## Supported features

* Anchors (`^`, `$`)
* Any character (`.`)
* Digit (`\d`) and whitespace (`\s`)
* Basic character classes (ex: `[^abc]`, `[A-Fa-f]`)
* Quantifiers (`*`, `?`, `+`, `{}`)
* Capturing and non-capturing groups (`(.+)`, `(?:.+)`)
* Escaping
