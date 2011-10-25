# (C) Copyright 2011, Biffnetworking.corp

# This file is part of Biff-NLP.

.SUFFIXES: .cc .u
CC= g++
CFLAGS= -O3 -Wall -g -lpthread
LDFLAGS= -lm

LOBJECTS= Run.o Container.o WordsCutter.o IDFDict.o SimilarityCalc.o WordSimilarity.o WordContainer.o

LSOURCE= Run.cc Container.cc WordsCutter.cc IDFDict.cc SimilarityCalc.cc WordSimilarity.cc WordContainer

LOBJECTS2= Container.o WordsCutter.o TrainCorpus.o IDFDict.o WordSimilarity.o WordContainer.o

LSOURCE2= Container.cc WordsCutter.cc TrainCorpus.cc IDFDict.cc WordSimilarity.cc WordContainer.cc

calc:	$(LOBJECTS)
	$(CC) $(CFLAGS) $(LOBJECTS) -o calc $(LDFLAGS)
trainCorpus: $(LOBJECTS2)  
	$(CC) $(CFLAGS) $(LOBJECTS2) -o trainCorpus $(LDFLAGS)
clean:
	rm -f *.o
