CC := clang
CFLAGS := -Wall -Wextra -std=c11
ASANFLAGS := -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer

# Normal build
gameOfLife: gameOfLife.c
	$(CC) $(CFLAGS) -g -o $@ $<

# ASan build -> different filename so Make doesn't “optimize” it away
gameOfLife_asan: gameOfLife.c
	$(CC) $(CFLAGS) $(ASANFLAGS) -o $@ $<

# Convenience targets
asan: gameOfLife_asan

run: gameOfLife
	./gameOfLife

run-asan: gameOfLife_asan
	./gameOfLife_asan

clean:
	rm -f gameOfLife gameOfLife_asan
.PHONY: asan run run-asan clean
