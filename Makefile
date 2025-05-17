all: bbazelisk

bbazelisk: bbazelisk.c
	cosmocc -o bbazelisk bbazelisk.c

clean:
	rm -f bbazelisk{,.com.dbg,.aarch64.elf}

.PHONY: all clean
