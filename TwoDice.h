//
// Created by Kaung Myat San on 4/11/24.
//

#ifndef OOP_PROJECT_THROWN_TWODICE_H
#define OOP_PROJECT_THROWN_TWODICE_H


#include "OneDice.h"

class TwoDice : public OneDice{
private:
    int secondThrown;
public:
    TwoDice();
    void thrownTwoDices();
    int giveFirstThrownResult();
    int giveSecondThrownResult() ;
    ~TwoDice();
};


#endif //OOP_PROJECT_THROWN_TWODICE_H
