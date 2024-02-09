CC = g++
CFLAGS = -Wall -Wextra -g3 -O0 -std=c++11

TARGET = perf_sort_example
SRC = perf_sort_example.cpp

TARGET += perf_unsort_example
SRC += perf_unsort_example.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET) perf.data*
