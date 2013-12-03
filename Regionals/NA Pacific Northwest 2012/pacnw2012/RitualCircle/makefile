CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all: RitualCircle RitualCircle.pdf RitualCircle.class

RitualCircle: RitualCircle.cpp
	$(CXX) $(CFLAGS) -o RitualCircle RitualCircle.cpp

RitualCircle.class: RitualCircle.java
	javac RitualCircle.java

RitualCircle.pdf: RitualCircle.tex RitualCircle.sample.in RitualCircle.sample.out
	pdflatex RitualCircle.tex

test: all
	perl validate.pl < RitualCircle.in
	perl validate.pl < RitualCircle.sample.in
	time ./RitualCircle < RitualCircle.in > t.out
	diff RitualCircle.out t.out
	time ./RitualCircle < RitualCircle.sample.in > t.out
	diff RitualCircle.sample.out t.out

testall: all
	perl validate.pl < RitualCircle.in
	perl validate.pl < RitualCircle.sample.in
	time ./RitualCircle < RitualCircle.in > t.out
	diff RitualCircle.out t.out
	time ./RitualCircle < RitualCircle.sample.in > t.out
	diff RitualCircle.sample.out t.out
	time java $(JAVAOPTS) RitualCircle < RitualCircle.in > t.out
	perl check.pl RitualCircle.out t.out
