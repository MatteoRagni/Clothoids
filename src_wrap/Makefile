PYTHON = python3

.PHONY: all clean

all: test

test: compile
	$(PYTHON) test.py

compile: 
	$(PYTHON) setup.py build_ext --inplace

clean:
	rm -rf *.so build