CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = main
SRC		 = src/* inc/*

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)