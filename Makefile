TARGET = main.out
TST_TARGET = tests.out

HDRS = \
	   project/include

SRCS = \
	   project/src/main.c \
	   project/src/matrix.c

.PHONY: all main test clean

all: main test

main: $(SRCS)
	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS) -lm

clean:
	rm -f $(TARGET) $(TST_TARGET)
