#include<iostream>

void show_value(int a){
    std::cout << a <<std::endl;

    std::cout<< "show value" << std::endl;
}

int add(int a, int b){
    int c = a + b;
    return c;
}

int main()
{
    int x = add(10,20);
    show_value(x);

    return 0;
}