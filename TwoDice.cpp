//
// Created by Kaung Myat San on 4/11/24.
//

#include "TwoDice.h"

TwoDice::TwoDice(){

}

void TwoDice::thrownTwoDices() {
    secondThrown = Thrown::giveANumber();
}

int TwoDice::giveFirstThrownResult() {
    thrownOneDice();
    return getOneDiceThrown();
}

int TwoDice::giveSecondThrownResult()  {
    thrownTwoDices();
    return secondThrown;
}

TwoDice::~TwoDice() {

}



