#include <cstdio>
#include <algorithm>
#include <vector> // ��Ҫ�������ͷ�ļ�����Ϊʹ����vector

int main() {
    FILE *fin, *fout;
    int N, a[1000001]; // ���������㹻���Դ洢�������������

    // �������ļ�
    fin = fopen("sort.in", "r");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    // ��ȡN��ֵ
    fscanf(fin, "%d", &N);

    // ��ȡN������������a��
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &a[i]);
    }

    // ������a�е�Ԫ�ؽ�������
    std::sort(a, a + N);

    // ������ļ�
    fout = fopen("sort.out", "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin); // �ر������ļ�
        return 1;
    }

    // ������������д�뵽����ļ�
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", a[i]); // ÿ�����ֺ�����ӿո�
    }

    // �ر��ļ�
    fclose(fin);
    fclose(fout);

    return 0;
}
