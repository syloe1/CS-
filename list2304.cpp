/*
#include <iostream>
int main() {
    int x {0}; // �ⲿx�Ķ���
    auto lambda = [&x](int y) { // ͨ�����ò���x
        x = 1; // �޸��ⲿx��ֵ
        y = 2; // �����޸�yʵ���ϲ���Ӱ�촫�ݸ�lambda��ʵ��
        return x + y; // ����x��y�ĺ�
    };
    int local {0};
    std::cout << lambda(local) << ", " << x << ", " << local << '\n'; // ���lambda�ķ���ֵ���ⲿx��ֵ���Լ�local��ֵ
}
*/
#include <iostream>
int main() {
	int x {0};
	auto lambda = [x](int y) mutable {
		x = 1;
		y = 2;
		return x + y;
	};
	int local {0};
	std::cout << lambda(local) << ", " << x << ", " << local << '\n';
}

