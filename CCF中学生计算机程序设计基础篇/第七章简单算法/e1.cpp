/*
���֡�ը�����������Ƚ�����������������
ը������ĳ����������ȫ���������Χ�ڵ��������������Ҳ��������
����������Ӱ�졣ը����ը���������������η�ʽ��ɢ�ģ�ը����������
ɢ���룩��d��������ʾ���Դ���d���ֵ���
*/
#include <iostream>
using namespace std;
const int MAXN = 1030;

int cnt[MAXN][MAXN], n, d;

void work() {
    // ��ʼ����ά����
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cnt[i][j] = 0;
        }
    }

    cin >> d;
    cin >> n;

    // ��ȡÿ���������ͳ���
    for (int i = 1; i <= n; i++) {
        int x, y, l;
        cin >> x >> y >> l;

        // ����� (x, y) ��Χ�뾶Ϊ d �ĵ���ۼӳ���
        for (int xr = -d; xr <= d; xr++) {
            if (x + xr >= 0 && x + xr < MAXN) {
                for (int yr = -d; yr <= d; yr++) {
                    if (y + yr >= 0 && y + yr < MAXN) {
                        cnt[x + xr][y + yr] += l;
                    }
                }
            }
        }
    }

    // �ҳ��ۼӳ��ȵ����ֵ������ִ���
    int maxval = -1, num = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (cnt[i][j] > maxval) {
                maxval = cnt[i][j];
                num = 1;
            } else if (cnt[i][j] == maxval) {
                num++;
            }
        }
    }

    // ������
    cout << num << " " << maxval << endl;
}

int main() {
    work();
    return 0;
}
