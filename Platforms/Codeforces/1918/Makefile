D ?= 0
ifeq ($(D), 1)
	CXXFLAGS=-O2 -std=c++20 -Wall -g -H -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
else
	CXXFLAGS=-O2 -std=c++20 -Wall -g -H -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DKaushal_26
endif

clean:
	find . -maxdepth 1 -type f -executable -delete
