
# BinaryHistory v1.0


The goal of this program is to respond to a problem that was introduced to me at the end of the third year of computer engineer at INSA Toulouse, during the design of a program for transmitting a video via TCP but at the help to recover, partial and not visually impacting, losses. The goal was therefore to keep track of events: transmitted or loss.

This program, thanks to the algorithm it implements, makes it possible to calculate the percentage of occurrences of a given event contained in a history of smaller size than a history of integers, booleans or else.

## Sample history bank

|History size (bits)   |History content          |`0` occurrences (%)  |`1` occurrences (%)  |
|----------------------|-------------------------|---------------------|---------------------|
|1                     |`[ 0 ]`                  |100.00               |0.00                 |
|2                     |`[ 0 1 ]`                |50.00                |50.00                |
|4                     |`[ 1 1 1 0 ]`            |25.00                |75.00                |
|8                     |`[ 0 1 1 0 1 0 0 0 ]`    |62.50                |37.50                |

To do so, modify the lines below present in the `testBinaryHistory.cpp` file at lines **29** to modify the size of the history and **48** to add occurrences to it.

```c++
// Create a new binary history with a size of 8 bits
BinaryHistory * eventHistory = new BinaryHistory(8u); // 8 : size in bits of the history
```

```c++
// Add some events in the history
eventHistory->add(true);
eventHistory->add(false);
eventHistory->add(true);
eventHistory->add(true);
eventHistory->add(false);
``` 

## Possible improvements

- Calculate the percentage of events not by browsing the history but rather based on an estimation