SHELL := /bin/bash
CC ?= clang

DESTDIR := rootfs
CPIO := rootfs.cpio
TARGET := exploit
OUT := $(TARGET)

SRCS := exploit.c

CPPFLAGS := -I.

CFLAGS := -Wall -masm=intel -static -std=c2x
LDFLAGS := -static -luring -lpthread

.PHONY: all compress decompress clean

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	mkdir -p $(DESTDIR)
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
