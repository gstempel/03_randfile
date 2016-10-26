GCC = gcc

rantest: randfile.c
	$(GCC) randfile.c -o rantest

run: rantest
	./rantest

clean:
	rm *~