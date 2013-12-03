CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all:  GoodVersusEvil GoodVersusEvil.pdf GoodVersusEvil.class good_v_evil_darthur

.PHONY: clean

GoodVersusEvil: GoodVersusEvil.cpp
	$(CXX) $(CFLAGS) -o GoodVersusEvil GoodVersusEvil.cpp

good_v_evil_darthur: good_v_evil_darthur.cpp
	$(CXX) $(CFLAGS) -o good_v_evil_darthur good_v_evil_darthur.cpp

GoodVersusEvil.class: GoodVersusEvil.java
	javac GoodVersusEvil.java

GoodVersusEvil.pdf: GoodVersusEvil.tex GoodVersusEvil.sample.in GoodVersusEvil.sample.out
	pdflatex GoodVersusEvil

test: all
	perl validate.pl < GoodVersusEvil.in
	perl validate.pl < GoodVersusEvil.sample.in
	./GoodVersusEvil < GoodVersusEvil.in > t.out
	diff GoodVersusEvil.out t.out
	./GoodVersusEvil < GoodVersusEvil.sample.in > t.out
	diff GoodVersusEvil.sample.out t.out

testall: all
	perl validate.pl < GoodVersusEvil.in
	perl validate.pl < GoodVersusEvil.sample.in
	time ./GoodVersusEvil < GoodVersusEvil.in > t.out
	diff GoodVersusEvil.out t.out
	./GoodVersusEvil < GoodVersusEvil.sample.in > t.out
	diff GoodVersusEvil.sample.out t.out
	time java $(JAVAOPTS) GoodVersusEvil < GoodVersusEvil.in > t.out
	diff GoodVersusEvil.out t.out
	time ./good_v_evil_darthur < GoodVersusEvil.in > t.out
	diff GoodVersusEvil.out t.out

clean:
	rm GoodVersusEvil
