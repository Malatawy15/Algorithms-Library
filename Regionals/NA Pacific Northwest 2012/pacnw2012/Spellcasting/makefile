all: Spellcasting.pdf Spellcasting.class spellcasting_darthur

CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m


Spellcasting.class: Spellcasting.java
	javac Spellcasting.java

spellcasting_darthur: spellcasting_darthur.cpp
	$(CXX) $(CFLAGS) -o spellcasting_darthur spellcasting_darthur.cpp

test: all
	perl validate.pl < Spellcasting.in
	perl validate.pl < Spellcasting.sample.in
	time java $(JAVAOPTS) Spellcasting < Spellcasting.in > t.out
	diff Spellcasting.out t.out
	java $(JAVAOPTS) Spellcasting < Spellcasting.sample.in > t.out
	diff Spellcasting.sample.out t.out

testall: all
	perl validate.pl < Spellcasting.in
	perl validate.pl < Spellcasting.sample.in
	time java $(JAVAOPTS) Spellcasting < Spellcasting.in > t.out
	diff Spellcasting.out t.out
	java $(JAVAOPTS) Spellcasting < Spellcasting.sample.in > t.out
	diff Spellcasting.sample.out t.out
	time ./spellcasting_darthur < Spellcasting.in > t.out
	diff Spellcasting.out t.out

Spellcasting.pdf: Spellcasting.tex Spellcasting.sample.in Spellcasting.sample.out
	pdflatex Spellcasting
