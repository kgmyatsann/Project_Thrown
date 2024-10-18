//
// Created by Kaung Myat San on 4/11/24.
//
/*
 * Thrown.h
 *
 */

#ifndef OOP_PROJECT_THROWN_THROWN_H
#define OOP_PROJECT_THROWN_THROWN_H


#include<cstdlib>
#include<iostream>

#include<cassert>
using namespace std;

class Thrown {
private:
    int m_range = 4;
public:
    Thrown();
    Thrown(int range);
    int giveANumber();
    virtual ~Thrown();
};

#endif
