#include<bits/stdc++.h>

class TEST{
    public:
        int figure;
        void calc(int temp);
        void second();
};

void TEST::calc(int temp){
    figure = temp;
    std::cout << figure <<std::endl;
    second();
}

void TEST::second(){
    std::cout << "second:" << figure <<std::endl;
}


int main(){
    TEST test;
    test.calc(10);
    
    return 0;
}