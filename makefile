rantest: randfile.c
	gcc randfile.c -o rantest

run: rantest
	./rantest

clean:
	rm *~