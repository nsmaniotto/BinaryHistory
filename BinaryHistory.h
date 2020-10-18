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
