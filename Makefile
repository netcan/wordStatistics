CXX = clang++
ARGS = -std=c++11

wordStatistics: wordStatistics.cpp
	$(CXX) $(ARGS) -o $@ $<
