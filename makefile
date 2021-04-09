B = ./build
S = ./src
D = ./depend

DEPENDS = $(basename $(wildcard $(D)/*.cpp))
SRC = $(basename $(wildcard $(S)/*.cpp))
CFLAGS = -Wall -g -I$(D)

all: $(SRC)

$(SRC): $(DEPENDS:=.cpp)
	g++ $(CFLAGS) $(S)/$(@F:=.cpp) $^ -o $(B)/$(@F)
