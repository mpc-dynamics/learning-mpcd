all: test

test: test.cpp vect2.h
	g++ test.cpp -o test

clean: 
	rm -fr *o test