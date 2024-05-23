#include<bits/stdc++.h>

using namespace std;
//version up

class algorithm{
    public:
        
        double R_var(double x, double y);
        double Expression(double max, double min , double avg);
        double Rank_avg(string H, double x , double y);
        int control();
};

//式1
double algorithm::R_var(double x, double y){
    double avg  = x - y;
    if(avg >= 1)
    {
        return 1;
    }
    else if(avg < 0)
    {
        return 0.1;
    }
    else{
        return avg;
    }
}

//式2
double algorithm::Expression(double max, double min , double avg){

    double T = min + (abs(max - min)* abs(avg));
    return T;
}

 //平均値を求める
double algorithm::Rank_avg(string H, double x , double y)
{
    double avg = (x / y);
    cout << H <<"平均ランク値：" << avg << endl;
    return avg;
}

int algorithm::control()
{
    int First_node, Now_node;
    
    cout << "初期ノード数:" ;
    cin >> First_node;
    int A[First_node+9];

    cout <<"初期ノードランク値をそれぞれ入力"<<endl;

    for(int i = 1; i<= First_node; i++) cin >> A[i];

    int R_min_first = A[1];
    double First_sum = 0;
    for(int i = 1; i<= First_node; i++) 
        {
            First_sum += A[i];
            R_min_first = min(R_min_first, A[i]);
        }

    //初期平均値を求める
    double First_avg = Rank_avg("初期" , First_sum , First_node);     
    cout << "現在のノード数:" ;
    cin >> Now_node;
    int B[Now_node+9];

    cout <<"現在の隣接ノードランク値をそれぞれ入力"<<endl;
    for(int i = 1; i<= Now_node; i++) cin >> B[i];

    double Now_sum = 0;
    int R_min_now = B[1], R_max_now = 0;

    for(int i = 1; i<= Now_node; i++) 
    {
        R_max_now = max(R_max_now, B[i]);
        R_min_now = min(R_min_now, B[i]);
        Now_sum += B[i];
    }

    //現在の平均ランク値出力
    double Now_avg = Rank_avg("現在" , Now_sum , Now_node);

    if(R_min_first == R_min_now)
    {
        cout << "最小値変化してないので経路変化なし" << endl;
        return 0;
    }

    //式4.1,4.2
    double R_avg = R_var(First_avg , Now_avg); 

    cout << "R_avg:"<< R_avg << endl;
    cout << "R_min_now, R_max_now:" << R_min_now <<", " << R_max_now <<endl;

    //式4.3
    double R_t = Expression(R_max_now, R_min_now, R_avg);

    cout << "閾値："<< R_t << endl;

    return 0;
}


int main(){
    
    algorithm first;
    first.control();

    return 0;
}