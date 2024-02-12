CC = g++
CFLAGS = -Wall -Wextra -g3 -std=c++17

TARGET_SORT = sort
SRC_SORT = sort.cpp

TARGET_UNSORT += unsort
SRC_UNSORT += unsort.cpp

all: $(TARGET_SORT) $(TARGET_UNSORT)

$(TARGET_SORT): $(SRC_SORT)
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET_UNSORT): $(SRC_UNSORT)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET_SORT) $(TARGET_UNSORT) perf.data*
