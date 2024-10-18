COMPILER = g++
FLAGS = -Iheaders -Wall #-g
SRC = $(wildcard source/*.cpp) 	# SRC holds all the files inside source folder

TARGET = a

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "Creating exec file called 'a'..."
	@$(COMPILER) $(FLAGS) -o $(TARGET) $(SRC) && echo "Run with './a' in your terminal." || echo "Errors compiling..."
	
	
clean:
	rm -f $(TARGET)
	

# if no make utility (installable by finding it in MinGW installation manager), run:
# g++ source/main.cpp etc...
