//
// Created by Kaung Myat San on 4/11/24.
//

#ifndef OOP_PROJECT_THROWN_COINTOSS_H
#define OOP_PROJECT_THROWN_COINTOSS_H

#include "Thrown.h"

class CoinToss : public Thrown{
private:
    int coinThrown;
public:
    CoinToss();
    void thrownOneCoin();
    int giveOneCoinThrownResult();
    virtual ~CoinToss();
};


#endif //OOP_PROJECT_THROWN_COINTOSS_H
