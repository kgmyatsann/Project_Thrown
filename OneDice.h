//
// Created by Kaung Myat San on 4/11/24.
//

#ifndef OOP_PROJECT_THROWN_ONEDICE_H
#define OOP_PROJECT_THROWN_ONEDICE_H


#include "Thrown.h"

class OneDice : public Thrown{
private:
    int OneDiceThrown;

public:
    OneDice();
    void thrownOneDice();
    int giveOneThrownResult();

    int getOneDiceThrown() const;

    void setOneDiceThrown(int oneDiceThrown);

    virtual ~OneDice();
};




#endif //OOP_PROJECT_THROWN_ONEDICE_H
