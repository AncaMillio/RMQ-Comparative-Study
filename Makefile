CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo.o algo1.o algo2.o algo3.o basic_algo.o
	g++ -o algo2 algo.o algo2.o $(CFLAGS)
	g++ -o algo3 algo.o algo3.o $(CFLAGS)
	g++ -o basic_algo algo.o basic_algo.o $(CFLAGS)
	g++ -o algo1 algo.o algo1.o $(CFLAGS)

algo.o: algo.cpp algo.h
	g++ -c algo.cpp $(CFLAGS)

algo1.o: algo1.cpp algo.cpp algo.h
	g++ -c algo1.cpp $(CFLAGS)

algo2.o: algo2.cpp algo.cpp algo.h
	g++ -c algo2.cpp $(CFLAGS)

algo3.o: algo3.cpp algo.cpp algo.h
	g++ -c algo3.cpp $(CFALGS)

basic_algo.o: basic_algo.cpp algo.cpp algo.h
	g++ -c basic_algo.cpp $(CFLAGS)

check:
	diff out/test_algo1_10_10.out out/test_basic_algo_10_10.out
	diff out/test_algo1_100_10.out out/test_basic_algo_100_10.out
	diff out/test_algo2_10_10.out out/test_basic_algo_10_10.out
	diff out/test_algo2_100_10.out out/test_basic_algo_100_10.out


.PHONY: clean
clean:
	rm -rf *.o
	rm -f algo1
	rm -f algo2
	rm -f algo3
	rm -f basic_algo
