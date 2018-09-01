TARGET=calci
CSRC=calci.c cal.c

CC=gcc
CFLAGS=
LDFLAGS=

COBJ=$(CSRC:.c=.o)

$(TARGET): $(COBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(COBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $<
