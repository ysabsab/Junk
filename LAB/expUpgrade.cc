#include<bits/stdc++.h>

using namespace std;
//version up

class algorithm{
    public:
        
        double R_var(double x, double y);
        double Expression(double max, double min , double avg);
        void Rank_avg(string x, double y);
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

    double Thredshold = min + (abs(max - min)* abs(avg));
    return Thredshold;
}

void algorithm::Rank_avg(string x, double y)
{
    cout << x <<"平均ランク値：" << y << endl;
}

int algorithm::control(){
    int First_node, Now_node;
    
    cout << "初期ノード数:" ;
    cin >> First_node;
    int A[First_node+9];

    cout <<"初期ノードランク値をそれぞれ入力"<<endl;
    for(int i = 1; i<= First_node; i++) cin >> A[i];

    int R_min_first = A[1];
    int R_max_first = 0;
    double First_avg = 0;
    for(int i = 1; i<= First_node; i++) 
        {
            First_avg += A[i];
            R_max_first = max(R_max_first, A[i]);
            R_min_first = min(R_min_first, A[i]);
        }

    First_avg = ((First_avg - R_max_first) / (First_node-1));

    Rank_avg("初期" , First_avg); //平均ランク値出力
    //cout <<"初期平均ランク値：" << First_avg << endl;

    cout << "現在のノード数:" ;
    cin >> Now_node;
    int B[Now_node+9];

    cout <<"現在の隣接ノードランク値をそれぞれ入力"<<endl;
    for(int i = 1; i<= Now_node; i++) cin >> B[i];

    double Now_avg = 0;

    int R_min_now = B[1], R_max_now = 0;

    for(int i = 1; i<= Now_node; i++) 
    {
        R_max_now = max(R_max_now, B[i]);
        R_min_now = min(R_min_now, B[i]);
        Now_avg += B[i];
    }

    Now_avg = ((Now_avg - R_max_now) / (Now_node - 1));

    Rank_avg("初期" , Now_avg); //平均ランク値出力

    if(R_min_first == R_min_now)
    {
        cout << "最小値変化してないので経路変化なし" << endl;
        return 0;
    }

    //cout <<"現在の平均ランク値：" << Now_avg << endl;

    //求める
    double R_avg = R_var(First_avg , Now_avg); 

    cout << "R_avg:"<< R_avg << endl;
    cout << "R_min_now, R_max_now:" << R_min_now <<", " << R_max_now <<endl;
    
    //double R_t = R_min_now + (abs(R_max_now - R_min_now)* abs(R_avg));
    double R_t = Expression(R_max_now, R_min_now, R_avg);

    cout << "閾値："<< R_t << endl;

    return 0;
}


int main(){
    
    algorithm first;
    first.control();

    return 0;
}