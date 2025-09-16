SHELL:=/bin/bash
CC ?= clang
STRIP ?= strip
DEBUG ?= 0

DESTDIR := root
CPIO := rootfs.cpio
TARGET := exploit_krop
OUT := $(TARGET)

SRCS := exploit_krop.c

BASE := -Wall -masm=intel -static -std=c2x
LDFLAGS := -static

ifeq ($(DEBUG),1)
CFLAGS := $(BASE) -O0 -g
else
CFLAGS := $(BASE) -O2 -march=native
endif

.PHONY: all compress decompress clean
all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
ifneq ($(DEBUG),1)
	$(STRIP) --strip-all $@ || true
endif
	cp $(OUT) $(DESTDIR)


compress: all
	cd $(DESTDIR) && \
	find . -print0 \
	| cpio --null -ov --format=newc -R root > ../$(CPIO)


decompress:
	mkdir -p $(DESTDIR) && \
	cd $(DESTDIR) && \
	find . -print0 \
	| cpio --null -i --format=newc -R root < ../$(CPIO)
	rm -f ../$(CPIO) || true


clean:
	rm -f $(OUT) || true
