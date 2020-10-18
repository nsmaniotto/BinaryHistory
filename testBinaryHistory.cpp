#include <stdio.h>
#include "BinaryHistory.h"

//extern BinaryHistory;

int main(int argc, char ** argv)
{
    double falseOccurrencesPercentage;
    double trueOccurrencesPercentage;

    // Create a new binary history
    BinaryHistory * eventHistory = new BinaryHistory(8u); // 8 : size in bits of the history

    printf("Event history size : %d\n", eventHistory->getHistorySize());

    // Display the previously created binary history
    eventHistory->display();


    // Calculate percentage of '0' occurring
    falseOccurrencesPercentage = eventHistory->calculatePercentageOf(false);

    printf("BEFORE : Percentage of 'false' found in the binary history : %.2f%%\n", falseOccurrencesPercentage);

    // Calculate percentage of '1' occurring
    trueOccurrencesPercentage = eventHistory->calculatePercentageOf(true);

    printf("BEFORE : Percentage of 'true' found in the binary history : %.2f%%\n", trueOccurrencesPercentage);


    // Add some events in the history
    eventHistory->add(true);
    eventHistory->add(false);
    eventHistory->add(true);
    eventHistory->add(true);
    eventHistory->add(false);


    // Display the previously created binary history
    eventHistory->display();


    // Calculate percentage of '0' occurring
    falseOccurrencesPercentage = eventHistory->calculatePercentageOf(false);

    printf("AFTER : Percentage of 'false' found in the binary history : %.2f%%\n", falseOccurrencesPercentage);

    // Calculate percentage of '1' occurring
    trueOccurrencesPercentage = eventHistory->calculatePercentageOf(true);

    printf("AFTER : Percentage of 'true' found in the binary history : %.2f%%\n", trueOccurrencesPercentage);

    return 0;
}
