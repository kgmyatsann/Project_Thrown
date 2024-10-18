#include <iostream>
#include "Thrown.h"
#include "CoinToss.h"
#include "OneDice.h"
#include "TwoDice.h"
#include <utility>

int countNumOfDigitsOF_ID(int s_ID){
    int numDigits = 0;
    int tempNumber = s_ID;
    while (tempNumber != 0) {
        tempNumber /= 10;
        numDigits++;
    }
    return numDigits;
}

pair<int,int> splitID(int s_ID){
    int group1,group2;
    int numDigits = countNumOfDigitsOF_ID(s_ID);
    if(numDigits % 2 == 0) {                                                         // even number student number
        int divisor = pow(10, numDigits / 2);
        group1 = s_ID / divisor;
        group2 = s_ID % divisor;
    }
    else{                                                                       // odd number student number
        int midpointIndex = numDigits / 2;
        // Extract the two equal size parts from the student number
        int divisor = pow(10, midpointIndex);
        group1= (s_ID / divisor )/ 10;
        group2 = s_ID % divisor;
    }
    return make_pair(group1,group2);
}

int countNtimes(int firstSplit , int secondSplit,int NumDigits){
    int sum = 0;
    int numOfEachSplit = NumDigits/2;
    for (int i = 1; i <= numOfEachSplit; ++i) {
        int digit1 = (firstSplit / (int)pow(10, numOfEachSplit - i)) % 10;
        int digit2 = (secondSplit / (int)pow(10, numOfEachSplit - i)) % 10;
        sum += digit1 * digit2;
    }
    int remainder = sum % 50;
    int totalTosses = remainder + 20;

    return totalTosses;
}

int* remainderOfZero(int nTimes){
    //static int coinTossResults[nTimes];
    int *coinTossResults = new int[nTimes];
    CoinToss ct;
    for(int i = 0; i < nTimes ; i++){
        coinTossResults[i] = ct.giveOneCoinThrownResult();
    }
    return coinTossResults;
}

int* remainderOfOne(int nTimes){
    int *oneDiceThrowResults = new int[nTimes];
    OneDice od;
    for(int i = 0; i < nTimes ; i++){
        oneDiceThrowResults[i] = od.giveOneThrownResult();
    }
    return oneDiceThrowResults;
}

int* remainderOfTwo(int nTimes){
    int i;
    int *twoDicesThrownResults = new int[nTimes*2];
    TwoDice td;
    for(i = 0; i < nTimes ; i++){
        twoDicesThrownResults[i] = td.giveFirstThrownResult();
    }
    for(i = nTimes; i < nTimes*2 ; i++){
        twoDicesThrownResults[i] = td.giveSecondThrownResult();
    }
    return twoDicesThrownResults;
}
int main() {
    /*TwoDice td;
    td.thrownTwoDices();
    cout << td.giveFirstThrownResult() << "\t" << td.giveSecondThrownResult();*/
    int studentID , remainder;
    bool isNotValidID = true;
    do{
        cout << "Please enter your Student ID : ";
        cin >> studentID;
        if (studentID > 99999999){
            cout << "Invalid Input.Your student Number cannot be more than 8 Digits. Please try again." << endl;
        }
        else if(studentID < 10){
            cout << "Invalid Input.Your student Number cannot be less than 2 Digits. Please try again." << endl;
        }
        else{
            isNotValidID = false;

            pair<int,int> ID_split = splitID(studentID);
            int numOfSimulation = countNtimes(ID_split.first,ID_split.second, countNumOfDigitsOF_ID(studentID));

            remainder = studentID % 3;
            int* ptr;
            switch (remainder) {
                case 0 : ptr = remainderOfZero(numOfSimulation); //address of a
                         cout << studentID << " / 3 = " << remainder << endl;
                         cout << "Therefore a coin is tossed." << endl;
                         cout << "Number of coin toss are : " << numOfSimulation << endl;
                         cout << "The results of coin toss are : " << endl;
                         for(int i=0 ; i<numOfSimulation; i++){
                             if(ptr[i] == 1)    cout << "Heads" << endl;
                             else if(ptr[i] == 2)   cout << "Tails" << endl;
                         }
                         delete[] ptr;
                         ptr = nullptr;
                         break;
                case 1 : ptr = remainderOfOne(numOfSimulation);
                         cout << studentID << " / 3 = " << remainder << endl;
                         cout << "Therefore 1 dice is thrown." << endl;
                         cout << "Number of One dice thrown are : " << numOfSimulation << endl;
                         cout << "The results of one dice thrown are : " << endl;
                         for(int i = 0; i < numOfSimulation ; i++){
                             cout << ptr[i] << endl;
                         }
                         delete[] ptr;
                         ptr = nullptr;
                         break;
                case 2 : ptr = remainderOfTwo(numOfSimulation);
                         cout << studentID << " / 3 = " << remainder << endl;
                         cout << "Therefore 2 dices are thrown." << endl;
                         cout << "Number of Two dice thrown are : " << numOfSimulation << endl;
                         cout << "The results of Two dice thrown are : " << endl;
                         for(int i = 0 ; i < numOfSimulation ; i++){
                            cout << ptr[i] << "\t" << ptr[i+numOfSimulation] << endl;
                         }
                         delete[] ptr;
                         ptr = nullptr;
                         break;

                default:    ;
            }
        }
    } while (isNotValidID);

    return 0;
}
