
TARGET=07_fifo_sched

XENO=/usr/xenomai
SKIN=native
XENO_CONFIG=$(XENO)/bin/xeno-config
XENO_CFLAGS=`$(XENO_CONFIG) --skin=$(SKIN) --cflags`
XENO_LDFLAGS=`$(XENO_CONFIG) --skin=$(SKIN) --ldflags`

$(TARGET): $(TARGET).c
	gcc -o $@ $(XENO_CFLAGS) $(XENO_LDFLAGS) $^

clean:
	rm -f $(TARGET)
