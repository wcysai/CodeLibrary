PEDANTIC_CXXFLAGS = -Iincludes/debug/includes -std=c++20 -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -DDEBUG -DLOCAL -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -fsanitize-address-use-after-scope
PEDANTIC_CFLAGS = -std=c17 -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -DDEBUG -DLOCAL -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -fsanitize-address-use-after-scope

NORMAL_CXXFLAGS = -Iincludes -std=c++20 -O2 -DTIMING -DLOCAL -ftree-vectorize 
NORMAL_CFLAGS = -std=c17 -O2 -DTIMING -DLOCAL -ftree-vectorize 

PARALLEL_CXXFLAGS = -fopenmp
PARALLEL_CFLAGS = -fopenmp

D ?= 0

P ?= 0

ifeq ($(D), 1)
	CXXFLAGS = $(PEDANTIC_CXXFLAGS)
	CFLAGS = $(PEDANTIC_CFLAGS)
else
	CXXFLAGS = $(NORMAL_CXXFLAGS)
	CFLAGS = $(NORMAL_CFLAGS)
endif

ifeq ($(P), 1)
	CXXFLAGS += $(PARALLEL_CXXFLAGS)
	CFLAGS += $(PARALLEL_CFLAGS)
endif

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm -f *.plist
