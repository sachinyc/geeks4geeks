#include<stdio.h>
#include<iostream>

int main()
{
    int num;
    std::cout<<" Enter the num"<<std::endl;
    std::cin>> num;

    if(! (num & (num -1)))
        std::cout<<"Power of 2"<<std::endl;
    else
        std::cout<<"not a power of 2"<<std::endl;


    return 0;
}

