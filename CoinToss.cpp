//
// Created by Kaung Myat San on 4/11/24.
//

#include "CoinToss.h"

CoinToss::CoinToss() {

}

void CoinToss::thrownOneCoin() {
    //Thrown tCoinToss(2);
    coinThrown = Thrown::giveANumber();
}

int CoinToss::giveOneCoinThrownResult() {
    thrownOneCoin();
    return coinThrown;
}
CoinToss::~CoinToss() {

}

