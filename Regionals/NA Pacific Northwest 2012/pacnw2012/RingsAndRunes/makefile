RELEASE_TARGETS = ringsandrunes_kj  ringsandrunes_tr.class ringsandrunes_da ringsandrunesProblemStatement.pdf
TESTING_TARGETS = ringsandrunes_kj  ringsandrunes_kj.out ringsandrunes_da  ringsandrunes_da.out ringsandrunes_tr.class ringsandrunes_tr.out
BINARY_TARGETS = ringsandrunes_kj  ringsandrunes_tr.class ringsandrunes_da
JUDGING_TARGETS = ringsandrunes_kj  RingsAndRunes.out
CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

.PHONY: test clean

all: $(RELEASE_TARGETS)
judge: $(JUDGING_TARGETS)


ringsandrunesProblemStatement.pdf: ringsandrunesProblemStatement.tex RunesAndRings.png ringsandrunes.sample.in ringsandrunes.sample.out
	pdflatex ringsandrunesProblemStatement.tex
	rm -f *.{dvi,aux,log} 

ringsandrunes_kj : ringsandrunes_kj.cpp
	$(CXX) $(CFLAGS) -o ringsandrunes_kj ringsandrunes_kj.cpp

ringsandrunes_da : ringsandrunes_da.cpp
	$(CXX) $(CFLAGS) -o ringsandrunes_da ringsandrunes_da.cpp
	
ringsandrunes_tr.class: ringsandrunes_tr.java
	javac ringsandrunes_tr.java

ringsandrunes_kj.out: ringsandrunes_kj RingsAndRunes.in RingsAndRunes.out
	date
	./ringsandrunes_kj  <RingsAndRunes.in >ringsandrunes_kj.out
	date
	diff ringsandrunes_kj.out RingsAndRunes.out

ringsandrunes_da.out: ringsandrunes_da RingsAndRunes.in RingsAndRunes.out
	date
	./ringsandrunes_da  <RingsAndRunes.in >ringsandrunes_da.out	
	date
	diff ringsandrunes_da.out RingsAndRunes.out
	
ringsandrunes_tr.out: ringsandrunes_tr.class RingsAndRunes.in RingsAndRunes.out
	date
	java ringsandrunes_tr <RingsAndRunes.in >ringsandrunes_tr.out
	date
	diff ringsandrunes_tr.out RingsAndRunes.out

RingsAndRunes.out:
	./ringsandrunes_kj  <RingsAndRunes.in >RingsAndRunes.out

ringsandrunes.sample.out:
	./ringsandrunes_kj  <ringsandrunes.sample.in >ringsandrunes.sample.out
	
ringsandrunes.sample.in:
	echo "Sample input file: ringsandrunes.sample.in"

test: $(BINARY_TARGETS)
	perl validate.pl < RingsAndRunes.in
	perl validate.pl < ringsandrunes.sample.in
	time ./ringsandrunes_kj < RingsAndRunes.in > t.out
	diff RingsAndRunes.out t.out
	./ringsandrunes_kj < ringsandrunes.sample.in > t.out
	diff ringsandrunes.sample.out t.out

testall: $(BINARY_TARGETS)
	perl validate.pl < RingsAndRunes.in
	perl validate.pl < ringsandrunes.sample.in
	time ./ringsandrunes_kj < RingsAndRunes.in > t.out
	diff RingsAndRunes.out t.out
	./ringsandrunes_kj < ringsandrunes.sample.in > t.out
	diff ringsandrunes.sample.out t.out
	time ./ringsandrunes_da < RingsAndRunes.in > t.out
	diff RingsAndRunes.out t.out
	time java $(JAVAOPTS) ringsandrunes_tr < RingsAndRunes.in > t.out
	diff RingsAndRunes.out t.out

clean:
	rm -f *.{o,dvi,aux,log} $(RELEASE_TARGETS) $(TESTING_TARGETS)
