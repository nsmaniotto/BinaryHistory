/******************************************************************************

Last modification : 18/10/2020

Author : Nathan Smaniotto

Github : https://github.com/nsmaniotto/BinaryHistory

Class : Calculate the percentage of a given occurrence in a binary history.

Version : 1.0

*******************************************************************************/

#ifndef BINARYHISTORY_H
#define BINARYHISTORY_H

#include <stdlib.h>
#include <stdio.h>

class BinaryHistory
{
    private:
        unsigned int * history;

        unsigned int historySize; // size in bits

    public:
        BinaryHistory(unsigned int);
        ~BinaryHistory();

        unsigned int getHistory() const;

        unsigned int getHistorySize() const;

        void add(bool);

        double calculatePercentageOf(bool);

        void display() const;
};

#endif // BINARYHISTORY_H
