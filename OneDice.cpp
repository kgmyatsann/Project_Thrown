//
// Created by Kaung Myat San on 4/11/24.
//

#include "OneDice.h"

/*OneDice::OneDice() : Thrown(6){

}*/
OneDice::OneDice():Thrown(6){

}

void OneDice::thrownOneDice(){
    OneDiceThrown = Thrown::giveANumber();
}

int OneDice::giveOneThrownResult() {
    thrownOneDice();
    return OneDiceThrown;
}

OneDice::~OneDice(){

}

int OneDice::getOneDiceThrown() const{
    return OneDiceThrown;
}

void OneDice::setOneDiceThrown(int oneDiceThrown) {
    OneDiceThrown = oneDiceThrown;
}



