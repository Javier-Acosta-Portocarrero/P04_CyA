CXX = g++
CXXFLAGS = -Wall -std=c++11 

TARGET = cya-P04-regex

SOURCES = analizador_programa.cc bucle.cc cliente_analizador_programa.cc comentario.cc variable.cc

OBJECTS = $(SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

cleano:
	rm -f $(OBJECTS)

.PHONY: all clean cleano