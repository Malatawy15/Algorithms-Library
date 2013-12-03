CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all: PaintedCube QuickPaintedCube FastPaintedCube PaintedCube.pdf PaintedCube_UM painted_cube_darthur PaintedCubeAN.class

PaintedCube: PaintedCube.cpp
	$(CXX) $(CFLAGS) -o PaintedCube PaintedCube.cpp

PaintedCube_UM: PaintedCube_UM.cpp
	$(CXX) $(CFLAGS) -o PaintedCube_UM PaintedCube_UM.cpp

FastPaintedCube: FastPaintedCube.cpp
	$(CXX) $(CFLAGS) -o FastPaintedCube FastPaintedCube.cpp

QuickPaintedCube: QuickPaintedCube.cpp
	$(CXX) $(CFLAGS) -o QuickPaintedCube QuickPaintedCube.cpp

PaintedCubeAN.class: PaintedCubeAN.java
	javac PaintedCubeAN.java

painted_cube_darthur: painted_cube_darthur.cpp
	$(CXX) $(CFLAGS) -o painted_cube_darthur painted_cube_darthur.cpp

test: all
	perl validate.pl < PaintedCube.in
	perl validate.pl < PaintedCube.sample.in
	time ./PaintedCube < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	./PaintedCube < PaintedCube.sample.in > t.out
	diff PaintedCube.sample.out t.out

testall: all
	perl validate.pl < PaintedCube.in
	perl validate.pl < PaintedCube.sample.in
	time ./PaintedCube < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	./PaintedCube < PaintedCube.sample.in > t.out
	diff PaintedCube.sample.out t.out
	time ./QuickPaintedCube < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	time ./FastPaintedCube < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	time ./PaintedCube_UM < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	time ./painted_cube_darthur < PaintedCube.in > t.out
	diff PaintedCube.out t.out
	time java $(JAVAOPTIONS) PaintedCubeAN < PaintedCube.in > t.out
	diff PaintedCube.out t.out

PaintedCube.pdf: PaintedCube.tex PaintedCube.sample.in PaintedCube.sample.out
	pdflatex PaintedCube
