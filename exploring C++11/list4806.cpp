template<class InputIterator , class T>
InputIterator find(InputIterator start, InputIterator end, T value) {
	for (; start != end; ++start)
		if (*start == value) 
			return start;
	return end;
}
