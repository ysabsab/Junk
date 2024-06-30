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

    double standard_deviation =  sqrt(sum / data.size());
    return standard_deviation;
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

//Zスコアを表示する関数
void print_zScore(const vector<double>& zScores, int count)
{
    cout << "Zスコア" << count << "回目: " ;
    for(double zScore: zScores) {
        cout << zScore << " ";
    }
    cout << endl;
}

int main() {
    vector<double> First_data = {7,7,8,9};
    //vector<double> Second_data = {3,3,7,7,8,9,10};
    vector<double> Second_data = {5,6,7,7,8,9,13};

    vector<double> zScores_First = calculateZScores(First_data);
    vector<double> zScores_Second = calculateZScores(Second_data);
    
    print_zScore(zScores_First, 1);
    print_zScore(zScores_Second, 2);
    
    return 0;
}
