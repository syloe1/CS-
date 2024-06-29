#include <iomanip>
#include <iostream>
#include <sstream>
class color {
	public: 
		color() : color {0, 0, 0} {} //Ĭ�Ϲ��캯��:
		color(color const&) = default; //���ƹ��캯��:
		color(int r, int g, int b) : red_ {r}, green_ {g}, blue_ {b} {} //���������캯��:
		
		//����������:
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
			return ((red() * 256L + green()) * 256) + blue(); //����һ����Ա������������ɫ�ĺ졢�̡���ֵ��ϳ�һ������������
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
	tmp << '#' << std::hex << std::setw(6) << std::setfill('0') << c.combined(); //std::hex������һ�����ݷ����������� std::ostringstream �Ļ���Ϊʮ�����ơ�
	//tmp << c.combined();  ��� color ��������ֵ:
	out << tmp.str(); //���ַ��������ַ��������ԭʼ��:
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
		std::basic_ios<char>& stream_; //std::basic_ios ��һ��ģ���࣬���ڷ�װ����/�������״̬��������־������ַ�����ߵȡ�char ���ַ����Ͳ�����ͨ������ std::cout��std::cin �ȱ�׼���� char ���͡�
		std::ios_base::fmtflags flags_; //std::ios_base �� I/O ���������� I/O ����Ļ����࣬�ṩ�˸�ʽ�����ƹ���
		//fmtflags ��һ�����Ͷ��壬ͨ����һ��λ�ֶΣ�bitfield������ʾ��ͬ�ĸ�ʽ����־�����磬�����Կ����Ƿ���ʾ�����ķ��š��Ƿ�ʹ�ö�����ѧ�������ȡ�
//flags_ ��Ա�����������ڴ洢���޸����ĸ�ʽ����־��
};
std::istream& operator>>(std::istream& in, color& c) {
	ioflags flags {in};
	char hash {};
	if (not (in >> hash))
		return in;
	if (hash != '#') {
// malformed color: no leading # character
		in.unget(); //// ���ַ��˻ص�������
		in.setstate(in.failbit); // ����ʧ��״̬
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
