# Makefile for building the examples distributed
# with SenseHat.

# Header files path (Update this with the library installation folder).
HEADERS_PATH = /usr/include

# Library path (Update this with the library installation folder).
LIBRARY_PATH = /usr/lib

# List of source files
SOURCES += printText.cpp thermometer.cpp barometer.cpp hygrometer.cpp menu.cpp weatherstation.cpp

#List of object files
OBJECTS += $(SOURCES:.cpp=.o)

all: printText thermometer barometer hygrometer menu weatherstation

#Compile all of the source files
%.o: %.cpp
	@echo Compiling file: $<
	g++ -I $(HEADERS_PATH) -std=c++0x -c $^ -o $@
	@echo
	
#Building weatherstation executable
weatherstation: weatherstation.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l ncurses -l SenseHat -l RTIMULib
	@echo

#Building menu executable
menu: menu.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l ncurses
	@echo

#Building printText executable
printText: printText.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo
	
#Building thermometer executable
thermometer: thermometer.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building hygrometer executable
hygrometer: hygrometer.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building barometer executable
barometer: barometer.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo


# Uninstall the exemples from the system
uninstall:
	rm -f  printText thermometer barometer hygrometer menu weatherstation


.PHONY: clean
clean:
	rm -f *.o

