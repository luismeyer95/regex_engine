# regex_engine
A simplified regex engine made in C++, heavily inspired from Denis Kyashif's implementation (https://deniskyashif.com/2019/02/17/implementing-a-regular-expression-engine/). Builds a non-deterministic finite automaton (NFA) using recursive-descent parsing and matches strings by traversing it.
The following symbols are implemented: '^' '$' '|' '.' '*' '?' '+' '\' [[^]set of characters] {quantifier range} 
