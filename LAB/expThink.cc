#include<bits/stdc++.h>

using namespace std;

double R_var(double x){
    if(x >= 0)
    {
        return 1;
    }
    else 
    {
        return 0.1;
    }
}

int main(){
    int First_node, Now_node;
    
    cout << "ノード数:" ;
    cin >> First_node;
    int A[First_node+9];

    cout <<"ノードランク値をそれぞれ入力"<<endl;
    for(int i = 1; i<= First_node; i++) cin >> A[i];

    // cout << "現在のノード数:" ;
    // cin >> Now_node;
    // int B[Now_node+9];

    // cout <<"現在の隣接ノードランク値をそれぞれ入力"<<endl;
    // for(int i = 1; i<= Now_node; i++) cin >> A[i];

    double Now_avg = 0;
    double first_avg = 7.5;
    double avg = 0;
    int R_min = A[1], R_max = 0;

    for(int i = 1; i<= First_node; i++) 
    {
        R_max = max(R_max, A[i]);
        R_min = min(R_min, A[i]);
        Now_avg += A[i];
    }

    Now_avg = (Now_avg / First_node);

    avg = first_avg - Now_avg;

    double R_avg = R_var(avg);

    

    double R_t = R_min + (abs(R_max - R_min)* abs(R_avg));

    cout << "閾値："<< R_t << endl;


    return 0;
}