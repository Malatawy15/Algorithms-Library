CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all: MagicMultiple MagicMultiple.pdf MagicMultiple.class magic_multiple_darthur
.PHONY: clean

clean:
	rm -f MagicMultiple *.aux *.log *.dvi

MagicMultiple: MagicMultiple.cpp
	$(CXX) $(CFLAGS) -o MagicMultiple MagicMultiple.cpp

MagicMultiple.class: MagicMultiple.java
	javac MagicMultiple.java

magic_multiple_darthur: magic_multiple_darthur.cpp
	$(CXX) $(CFLAGS) -o magic_multiple_darthur magic_multiple_darthur.cpp

test: all
	perl validate.pl < MagicMultiple.in
	perl validate.pl < MagicMultiple.sample.in
	time ./MagicMultiple < MagicMultiple.in > t.out
	diff MagicMultiple.out t.out
	./MagicMultiple < MagicMultiple.sample.in > t.out
	diff MagicMultiple.sample.out t.out

testall: all
	perl validate.pl < MagicMultiple.in
	perl validate.pl < MagicMultiple.sample.in
	time ./MagicMultiple < MagicMultiple.in > t.out
	diff MagicMultiple.out t.out
	./MagicMultiple < MagicMultiple.sample.in > t.out
	diff MagicMultiple.sample.out t.out
	time java $(JAVAOPTS) MagicMultiple < MagicMultiple.in > t.out
	diff MagicMultiple.out t.out
	time ./magic_multiple_darthur < MagicMultiple.in > t.out
	diff MagicMultiple.out t.out

MagicMultiple.pdf: MagicMultiple.tex MagicMultiple.sample.in MagicMultiple.sample.out
	pdflatex MagicMultiple
