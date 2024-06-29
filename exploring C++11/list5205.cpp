#include <cmath>   // 包含数学库，用于sqrt函数
#include <numeric> // 包含accumulate函数
#include <vector>  // 包含vector容器

namespace stats {
    // 定义一个计算平方和的函数对象，用于计算标准差
    class SumSquares {
    public:
        SumSquares(double mean) : mean_(mean) {} // 构造函数，初始化均值

        // 累加操作，用于accumulate函数
        double operator()(double acc, double x) const {
            return acc + square(x - mean_); // 累加每个数据点与均值差的平方
        }

        // 辅助函数，用于计算平方
        double square(double x) const { return x * x; }

    private:
        double mean_; // 存储均值
    };

    // 计算标准差的函数
    double calculateStandardDeviation(const std::vector<double>& data) {
        double stdDev{0.0}; // 标准差的变量，使用更合适的名称
        if (!data.empty()) { // 检查数据是否为空
            double sum = std::accumulate(data.begin(), data.end(), 0.0); // 计算总和
            double mean = sum / data.size(); // 计算均值
            SumSquares sumSquares(mean); // 创建SumSquares对象
            double sumsq = std::accumulate(data.begin(), data.end(), 0.0, sumSquares); // 计算平方和
            double variance = sumsq / data.size(); // 计算方差，这里减去mean * mean是不必要的
            stdDev = std::sqrt(variance); // 计算标准差
        }
        return stdDev; // 返回计算结果
    }
}

// 使用示例
// int main() {
//     std::vector<double> data = {1.0, 2.0, 3.0, 4.0};
//     double stdDev = stats::calculateStandardDeviation(data);
//     std::cout << "Standard Deviation: " << stdDev << std::endl;
//     return 0;
// }
