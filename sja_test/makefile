
GRT=..
INCDIRS=-I$(GRT)/gcore -I$(GRT)/build/gcore -I$(GRT)/port -I$(GRT)/build/port -I$(GRT)/ogr
LGDL=$(GRT)/build/libgdal.so

terrain : main.o $(LGDL)
	g++ -o terrain main.o $(LGDL)

main.o : main.cpp
	g++ $(INCDIRS) main.cpp -c -o main.o
	