CFLAGS=-Wall
CXX=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testBinaryHistory

testBinaryHistory: testBinaryHistory.o BinaryHistory.o
	$(LD) $@ $^

testBinaryHistory.o: testBinaryHistory.cpp BinaryHistory.h
	$(CXX) $<

BinaryHistory.o: BinaryHistory.cpp BinaryHistory.h
	$(CXX) $<

clean:
	rm testBinaryHistory *.o