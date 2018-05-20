OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA
OBJ_PATH=./obj/
SRC_PATH=./src/
PRED_PATH=./predictors/
SOURCE=$(wildcard $(SRC_PATH)*.cpp)
OBJS=$(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(SOURCE))
EXEC=main

all: $(OBJS)
	g++ $^ -o $(EXEC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(OPT) $< -o $@

install:
	mkdir -p $(OBJ_PATH)
	mkdir -p ./wav/broken
	mkdir -p ./wav/whole

pred: $(PRED_PATH)predictors.exe
	python $(PRED_PATH)wavetransform.py
	start $(PRED_PATH)predictors.exe

$(PRED_PATH)predictors.exe: $(PRED_PATH)predictors.cpp
	g++ -std=gnu++11 -O0 -Wall -Wextra -DCEMA $< -o $@

clean:
	rm -f $(OBJ_PATH)*.o
	rm -f $(PRED_PATH)broken
	rm -f $(PRED_PATH)whole