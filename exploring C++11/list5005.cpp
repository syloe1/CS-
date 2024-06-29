template <class T>
struct less {
	bool operator() (T const& a, T const& b) const {return a < b;}
};
