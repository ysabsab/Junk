#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>  // std::accumulate

using namespace std;

// 平均を計算する関数
double calculateMean(const vector<double>& data) {
    double sum = accumulate(data.begin(), data.end(), 0.0);
    double avg_sum = sum / data.size();
    return avg_sum;
}

// 標準偏差を計算する関数
double calculateStdDev(const vector<double>& data, double mean) {
    double sum = 0.0;
    for(double value : data) {
        sum += pow(value - mean, 2);
    }
    return sqrt(sum / data.size());
}

// Zスコアを計算する関数
vector<double> calculateZScores(const vector<double>& data) {
    double mean = calculateMean(data);
    double stdDev = calculateStdDev(data, mean);
    
    vector<double> zScores;
    for(double value : data) {
        zScores.push_back((value - mean) / stdDev);
    }
    return zScores;
}

int main() {
    vector<double> data = {3,3,7,7,8,9,10};
    
    vector<double> zScores = calculateZScores(data);
    
    cout << "Zスコア: ";
    for(double zScore : zScores) {
        cout << zScore << " ";
    }
    cout << endl;
    
    return 0;
}
