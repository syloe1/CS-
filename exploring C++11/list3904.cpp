#include <iomanip>
#include <iostream>
#include <sstream>
class color {
	public: 
		color() : color {0, 0, 0} {} //默认构造函数:
		color(color const&) = default; //复制构造函数:
		color(int r, int g, int b) : red_ {r}, green_ {g}, blue_ {b} {} //参数化构造函数:
		
		//访问器函数:
		int red() const {
			return red_;
		}
		int green() const {
			return green_;
		}
		int blue() const {
			return blue_;
		}
/// Because red(), green(), and blue() are supposed to be in the range [0,255],
/// it should be possible to add them together in a single long integer.
/// TODO: handle out of range
		long int combined() const {
			return ((red() * 256L + green()) * 256) + blue(); //这是一个成员函数，返回颜色的红、绿、蓝值组合成一个长整型整数
		}
	private:
		int red_, green_, blue_;
};
inline bool operator==(color const& a, color const& b) {
	return a.combined() == b.combined();
}
inline bool operator!=(color const& a, color const& b) {
	return not (a == b);
}
inline bool order_color(color const& a, color const& b) {
	return a.combined() < b.combined();
}
/// Write a color in HTML format: #RRGGBB.
std::ostream& operator<<(std::ostream& out, color const& c) {
	std::ostringstream tmp {};
// The hex manipulator tells a stream to write or read in hexadecimal (base 16).
	tmp << '#' << std::hex << std::setw(6) << std::setfill('0') << c.combined(); //std::hex：这是一个操纵符，用于设置 std::ostringstream 的基数为十六进制。
	//tmp << c.combined();  输出 color 对象的组合值:
	out << tmp.str(); //将字符串流的字符串输出到原始流:
	return out;
}
class ioflags {
	public:
/// Save the formatting flags from @p stream.
		ioflags(std::basic_ios<char>& stream) : stream_ {stream}, flags_ {stream.flags()} {}
		ioflags(ioflags const&) = delete;
/// Restore the formatting flags.
		~ioflags() {
			stream_.flags(flags_);
		}
	private:
		std::basic_ios<char>& stream_; //std::basic_ios 是一个模板类，用于封装输入/输出流的状态，如错误标志、填充字符、宽高等。char 是字符类型参数，通常对于 std::cout、std::cin 等标准流是 char 类型。
		std::ios_base::fmtflags flags_; //std::ios_base 是 I/O 流库中所有 I/O 基类的基础类，提供了格式化控制功能
		//fmtflags 是一个类型定义，通常是一个位字段（bitfield），表示不同的格式化标志。例如，它可以控制是否显示正数的符号、是否使用定点或科学计数法等。
//flags_ 成员变量可能用于存储和修改流的格式化标志。
};
std::istream& operator>>(std::istream& in, color& c) {
	ioflags flags {in};
	char hash {};
	if (not (in >> hash))
		return in;
	if (hash != '#') {
// malformed color: no leading # character
		in.unget(); //// 将字符退回到输入流
		in.setstate(in.failbit); // 设置失败状态
		return in;
	}
// Read the color number, which is hexadecimal: RRGGBB.
	int combined {};
	in >> std::hex >> std::noskipws;
	if (not (in >> combined))
		return in;
// Extract the R, G, and B bytes.
	int red, green, blue;
	blue = combined % 256;
	combined = combined / 256;
	green = combined % 256;
	combined = combined / 256;
	red = combined % 256;
// Assign to c only after successfully reading all the color components.
	c = color {red, green, blue};
	return in;
}
