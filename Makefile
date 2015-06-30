test: test.c priqueue.h
	gcc -o test test.c

run_tests: test
	./test
