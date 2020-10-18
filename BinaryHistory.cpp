#include "BinaryHistory.h"

// Creates an empty binary history
BinaryHistory::BinaryHistory(unsigned int size) : historySize(size)
{
    if(this->historySize == 0u)
    {
       this->historySize = 1u;
    }

     this->history = (unsigned int *)calloc(this->historySize, 1);

    *(this->history) = 0u;
}

BinaryHistory::~BinaryHistory()
{
    free(this->history);
}

unsigned int BinaryHistory::getHistory() const
{
    return *(this->history);
}

unsigned int BinaryHistory::getHistorySize() const
{
    return this->historySize;
}

void BinaryHistory::add(bool b)
{
    unsigned int newOccurrence = 0u;

    if(b)
    {
        newOccurrence = 1u;
    }

    *(this->history) = (*(this->history) << 1) + newOccurrence;
}

double BinaryHistory::calculatePercentageOf(bool searchedOccurrences)
{
    double bOccurrencesPercentage = 0.;
    unsigned int i;

    if(searchedOccurrences)
    {
        unsigned int * mask, bOccurrences = 0u;

        mask = (unsigned int *)calloc(this->historySize, sizeof(int));

        for(i = 0u; i < this->historySize; i++) {
            *mask = 1u << i;

            if((*(this->history) & *mask) == *mask)
            {
                bOccurrences++;
            }
        }

        bOccurrencesPercentage = (double)(bOccurrences * 100) / (double)this->historySize;

        free(mask);
    }
    else
    {
        bOccurrencesPercentage = 100. - this->calculatePercentageOf(!searchedOccurrences);
    }

    return bOccurrencesPercentage;
}

void BinaryHistory::display() const
{
    unsigned int * mask;
    unsigned int i;
    char occurrence;

    mask = (unsigned int *)calloc(this->historySize, sizeof(int));

    printf("[ ");

    for(i = 0u; i < this->historySize; i++)
    {
        occurrence = '0';

        *mask = 1u << i;

        if((*(this->history) & *mask) == *mask)
        {
            occurrence = '1';
        }

        printf("%c ", occurrence);
    }

    printf("]\n");

    free(mask);
}
