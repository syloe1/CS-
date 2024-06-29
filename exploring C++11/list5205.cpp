#include <cmath>   // ������ѧ�⣬����sqrt����
#include <numeric> // ����accumulate����
#include <vector>  // ����vector����

namespace stats {
    // ����һ������ƽ���͵ĺ����������ڼ����׼��
    class SumSquares {
    public:
        SumSquares(double mean) : mean_(mean) {} // ���캯������ʼ����ֵ

        // �ۼӲ���������accumulate����
        double operator()(double acc, double x) const {
            return acc + square(x - mean_); // �ۼ�ÿ�����ݵ����ֵ���ƽ��
        }

        // �������������ڼ���ƽ��
        double square(double x) const { return x * x; }

    private:
        double mean_; // �洢��ֵ
    };

    // �����׼��ĺ���
    double calculateStandardDeviation(const std::vector<double>& data) {
        double stdDev{0.0}; // ��׼��ı�����ʹ�ø����ʵ�����
        if (!data.empty()) { // ��������Ƿ�Ϊ��
            double sum = std::accumulate(data.begin(), data.end(), 0.0); // �����ܺ�
            double mean = sum / data.size(); // �����ֵ
            SumSquares sumSquares(mean); // ����SumSquares����
            double sumsq = std::accumulate(data.begin(), data.end(), 0.0, sumSquares); // ����ƽ����
            double variance = sumsq / data.size(); // ���㷽������ȥmean * mean�ǲ���Ҫ��
            stdDev = std::sqrt(variance); // �����׼��
        }
        return stdDev; // ���ؼ�����
    }
}

// ʹ��ʾ��
// int main() {
//     std::vector<double> data = {1.0, 2.0, 3.0, 4.0};
//     double stdDev = stats::calculateStandardDeviation(data);
//     std::cout << "Standard Deviation: " << stdDev << std::endl;
//     return 0;
// }
