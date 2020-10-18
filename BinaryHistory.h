#ifndef BINARYHISTORY_H
#define BINARYHISTORY_H

#include <stdlib.h>
#include <stdio.h>

class BinaryHistory
{
    private:
        unsigned int * history;

        unsigned int historySize; // size in bits

        unsigned int trueOccurrences; // A true occurrence is a '1'

        void updateTrueOccurrences(bool);

    public:
        BinaryHistory(unsigned int);
        ~BinaryHistory();

        unsigned int getHistory() const;

        unsigned int getHistorySize() const;

        unsigned int getOccurrencesOf(bool) const;

        double getPercentageOf(bool) const;

        void add(bool);

        void display() const;
};

#endif // BINARYHISTORY_H
