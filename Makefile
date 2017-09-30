CFILES=$(shell find -name '*.c')
OFILES=$(patsubst %.c,%.o,$(CFILES))
TARGET=Demo

FLAGS=-lpthread -lglfw3 -lopengl32 -lgdi32

$(TARGET): $(OFILES)
	gcc -o $(TARGET) $(OFILES) $(FLAGS)

%.o: %.cpp
	gcc -o $@ -c $<

clean:
	rm -rf $(TARGET) $(OFILES)
