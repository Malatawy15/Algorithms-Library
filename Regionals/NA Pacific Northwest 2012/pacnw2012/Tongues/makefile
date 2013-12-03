CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all: Tongues Tongues.pdf Tongues.class tongues_darthur

Tongues: Tongues.cpp
	$(CXX) $(CFLAGS) -o Tongues Tongues.cpp

Tongues.class: Tongues.java
	javac Tongues.java

tongues_darthur: tongues_darthur.cpp
	$(CXX) $(CFLAGS) -o tongues_darthur tongues_darthur.cpp

Tongues.pdf: Tongues.tex Tongues.sample.in Tongues.sample.out
	pdflatex Tongues

test: all
	perl validate.pl < Tongues.in
	perl validate.pl < Tongues.sample.in
	time ./Tongues < Tongues.in > t.out
	diff Tongues.out t.out
	./Tongues < Tongues.sample.in > t.out
	diff Tongues.sample.out t.out

testall: all
	perl validate.pl < Tongues.in
	perl validate.pl < Tongues.sample.in
	time ./Tongues < Tongues.in > t.out
	diff Tongues.out t.out
	./Tongues < Tongues.sample.in > t.out
	diff Tongues.sample.out t.out
	time java $(JAVAOPTS) Tongues < Tongues.in > t.out
	diff Tongues.out t.out
	time ./tongues_darthur < Tongues.in > t.out
	diff Tongues.out t.out
