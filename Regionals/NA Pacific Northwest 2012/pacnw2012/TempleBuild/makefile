all: TempleBuild TempleBuild.pdf TempleBuild.class temple_build_darthur

CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

TempleBuild: TempleBuild.cpp
	$(CXX) $(CFLAGS) -o TempleBuild TempleBuild.cpp

TempleBuild.class: TempleBuild.java
	javac TempleBuild.java

temple_build_darthur: temple_build_darthur.cpp
	$(CXX) $(CFLAGS) -o temple_build_darthur temple_build_darthur.cpp

TempleBuild.pdf: TempleBuild.tex TempleBuild.sample.in TempleBuild.sample.out
	pdflatex TempleBuild

test: all
	perl validate.pl < TempleBuild.in
	perl validate.pl < TempleBuild.sample.in
	time ./TempleBuild < TempleBuild.in > t.out
	diff t.out TempleBuild.out
	./TempleBuild < TempleBuild.sample.in > t.out
	diff t.out TempleBuild.sample.out

testall: all
	perl validate.pl < TempleBuild.in
	perl validate.pl < TempleBuild.sample.in
	time ./TempleBuild < TempleBuild.in > t.out
	diff t.out TempleBuild.out
	./TempleBuild < TempleBuild.sample.in > t.out
	diff t.out TempleBuild.sample.out
	time java $(JAVAOPTS) TempleBuild < TempleBuild.in > t.out
	diff t.out TempleBuild.out
	time ./temple_build_darthur < TempleBuild.in > t.out
	diff t.out TempleBuild.out
