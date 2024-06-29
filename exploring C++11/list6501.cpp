enum class openmode : unsigned {
    in, out, binary, trunc, app, ate
};
openmode operator|(openmode lhs, openmode rhs) {
	return static_cast<openmode>(
	           static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs) );
}
openmode operator&(openmode lhs, openmode rhs) {
	return static_cast<openmode>(
	           static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs) );
}
openmode operator~(openmode arg) {
	return static_cast<openmode>( ~static_cast<unsigned>(arg) );
}
