//�������reverse
 #include <cstdio>
#include <algorithm>
using namespace std;

int N, a[1000001]; // ��������a���洢���������

int main() {
    // �ض���ֻ���ļ�reverse.in��stdin
    freopen("reverse.in", "r", stdin);
    // �ض���ֻд�ļ�reverse.out��stdout
    freopen("reverse.out", "w", stdout);

    // ʹ�ñ�׼����scanf��ȡN��ֵ
    scanf("%d", &N);
    // ��ȡN������������a��
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // �����������a�е�Ԫ�ص���׼���
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", a[i]); // ʹ��printf�������ÿ�����ֺ�����ӿո�
    }

    // ����رձ�׼�������������Ϊ������ȫ�ֵ�
    return 0;
}
