//将字符串转换为整数 
int sti(char* str)  {
	int res = 0;
	while (*str != 0) {
		res = res * 10 + *str - '0';
		++str;
	}
	return res;
}
