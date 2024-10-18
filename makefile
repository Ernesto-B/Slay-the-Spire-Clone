COMPILER = g++
FLAGS = -Iheaders -Wall #-g
SRC = source/attack.cpp source/card.cpp source/enemy.cpp source/gameFrame.cpp source/main.cpp source/mon.cpp source/player.cpp

# MISSING ATTACK CARD AND BLOCK CARD SOURCES
# source/main.cpp source/attack.cpp source/mon.cpp source/player.cpp source/enemy.cpp source/
TARGET = a

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "Creating exec file called 'a'..."
	@$(COMPILER) $(FLAGS) -o $(TARGET) $(SRC) && echo "Run with './a' in your terminal." || echo "Errors compiling..."
	
	
clean:
	rm -f $(TARGET)
	

# if no make utility (installable by finding it in MinGW installation manager), run:
# g++ source/main.cpp etc...
