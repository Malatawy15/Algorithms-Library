CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

all: SarumansLevelUp SarumansLevelUp.pdf sarumans_level_up_darthur SarumansLevelUp.class

SarumansLevelUp: SarumansLevelUp.cpp
	$(CXX) $(CFLAGS) -o SarumansLevelUp SarumansLevelUp.cpp

SarumansLevelUp.class: SarumansLevelUp.java
	javac SarumansLevelUp.java

sarumans_level_up_darthur: sarumans_level_up_darthur.cpp
	$(CXX) $(CFLAGS) -o sarumans_level_up_darthur sarumans_level_up_darthur.cpp

SarumansLevelUp.pdf: SarumansLevelUp.tex SarumansLevelUp.sample.in SarumansLevelUp.sample.out
	pdflatex SarumansLevelUp

test: all
	perl validate.pl < SarumansLevelUp.in
	perl validate.pl < SarumansLevelUp.sample.in
	time ./SarumansLevelUp < SarumansLevelUp.in > t.out
	diff SarumansLevelUp.out t.out
	time ./SarumansLevelUp < SarumansLevelUp.sample.in > t.out
	diff SarumansLevelUp.sample.out t.out

testall: all
	perl validate.pl < SarumansLevelUp.in
	perl validate.pl < SarumansLevelUp.sample.in
	time ./SarumansLevelUp < SarumansLevelUp.in > t.out
	diff SarumansLevelUp.out t.out
	time ./SarumansLevelUp < SarumansLevelUp.sample.in > t.out
	diff SarumansLevelUp.sample.out t.out
	time ./sarumans_level_up_darthur < SarumansLevelUp.in > t.out
	diff SarumansLevelUp.out t.out
	time java $(JAVAOPTS) SarumansLevelUp < SarumansLevelUp.in > t.out
	diff SarumansLevelUp.out t.out
