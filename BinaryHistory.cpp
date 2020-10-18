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

void BinaryHistory::updateTrueOccurrences(bool addedOccurrence)
{
    unsigned int oldestOccurrence;
    unsigned int addedOccurrenceValue = 0u;

    if(addedOccurrence)
    {
        addedOccurrenceValue = 1u;
    }

    // Read the oldest occurrence
    oldestOccurrence = *(this->history) >> (this->historySize - 1);

    this->trueOccurrences -= oldestOccurrence;
    this->trueOccurrences += addedOccurrenceValue;
}

unsigned int BinaryHistory::getHistory() const
{
    return *(this->history);
}

unsigned int BinaryHistory::getHistorySize() const
{
    return this->historySize;
}

unsigned int BinaryHistory::getOccurrencesOf(bool b) const
{
    unsigned int occurrences = this->trueOccurrences;

    if(!b)
    {
        occurrences = this->historySize - this->trueOccurrences;
    }

    return occurrences;
}

double BinaryHistory::getPercentageOf(bool searchedOccurrence) const
{
    return (double)(this->getOccurrencesOf(searchedOccurrence) * 100) / (double)this->historySize;
}

void BinaryHistory::add(bool b)
{
    unsigned int newOccurrence = 0u;

    if(b)
    {
        newOccurrence = 1u;
    }

    *(this->history) = (*(this->history) << 1) + newOccurrence;

    this->updateTrueOccurrences(b);
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
