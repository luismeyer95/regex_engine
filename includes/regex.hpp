#pragma once

#include "header.h"

#include "NFA.hpp"
#include "PatternValidation.hpp"

template <typename M>
struct regexResult
{
	bool success;
	M	 matched;
};

class regex
{
	private:
		std::string							pattern;
		size_t								index;

		int									capture_index;

		bool								anchor_start;
		bool								anchor_end;

		std::vector<char>					alphabet;

		NFA 								axiom();
		NFA									expr(int capture);
		NFA									term();
		NFA									factor();
		NFA									modifier(NFA atm);
		NFA									quantify(NFA atm);
		NFA									atom();
		NFA									bracket();
		NFA									setof(bool include, std::vector<char>& set);
		void								subsetof(std::vector<char>& set);
		NFA									charset();
		
		char 								peek();
		char								next();
		void								eat(char token);
		bool								more();

		NFA									automaton;

		static std::string					escapeSymbols(const std::string& str);
		void								setNextStates
		(NFAState *state, std::vector<NFAState*>& next_states, std::vector<NFAState*>& visited) const;

		std::vector<NFAState*>::iterator	findEndState
		(std::vector<NFAState*>& end_states) const;

		void 								constructPath
		(const std::vector< std::vector<NFATransition> > & all_trans,
		std::vector<char>& path, std::vector<std::set<int>>& path_tags) const ;

		std::string							buildCapture
		(const std::vector<char>& path, const std::vector<std::set<int>>& tags, int capture) const;

		std::vector<std::string>			buildAllCaptures
		(const std::vector<char>& path, const std::vector<std::set<int>>& tags) const;

	public:
		regex();
		regex(const std::string& pattern);
		~regex();

		typedef regexResult<std::string> match_result;
		typedef regexResult<std::vector<std::string> > groupmatch_result;

		regex::match_result 				match(const std::string& str) const;
		regex::groupmatch_result 			groupmatch(const std::string& str) const;

};