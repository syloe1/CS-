template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator start, InputIterator end, OutputIterator result) {
	for (; start != end; ++start, ++result)
		*result = *start;
	return result;
}

