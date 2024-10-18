//
// Created by Kaung Myat San on 4/11/24.
//
/*
 * Thrown.cpp
 *
 */

#include "Thrown.h"
#include <random>

Thrown::Thrown() {
    // Providing a seed value
    //random_device rd;
    //uniform_int_distribution<int> dist(1,RAND_MAX);
    srand((unsigned) time(NULL));

}

Thrown::Thrown(int range)
:m_range(range)
{
    if(m_range <=0){
        cout<<"Range not valid. Program execution aborted... "<<endl;
    }
    // Providing a seed value
    //random_device rd;
    //uniform_int_distribution<int> dist(1,range);
    srand((unsigned) time(NULL));
}

int Thrown::giveANumber()
{
    /*random_device rd;
    uniform_int_distribution<int> dist(1,m_range);
    return dist(rd);*/
    return (std::rand() % m_range) + 1;
}

Thrown::~Thrown() {
    // TODO Auto-generated destructor stub
}


