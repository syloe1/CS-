template<class Char, class Traits, class Allocator>
bool is_palindrome(std::basic_string<Char, Traits, Allocator> str) {
	typedef typename std::basic_string<Char, Traits, Allocator> string;
	typename string::iterator end {
		std::remove_if(str.begin(), str.end(), non_letter<Char>)
	};
	string rev {str.begin(), end};
	std::reverse(rev.begin(), rev.end());
	return not rev.empty() and
	       std::equal(str.begin(), end, rev.begin(), same_char<Char>);
}
