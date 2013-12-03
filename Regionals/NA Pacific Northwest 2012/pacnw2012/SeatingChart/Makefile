TARGETS = \
	SeatingChart.pdf \
	SeatingChart \
	SeatingChartSlow SeatingChart.class seating_chart_darthur

CFLAGS = -O3 -lm
JAVAOPTS = -server -Xmx1600m -Xms100m

.PHONY: all clean test

all: $(TARGETS)

SeatingChart.pdf: SeatingChart.tex SeatingChart.sample.in SeatingChart.sample.out
	pdflatex SeatingChart.tex

SeatingChart: SeatingChart.cpp
	$(CXX) $(CFLAGS) -o SeatingChart -O2 SeatingChart.cpp

SeatingChartSlow: SeatingChartSlow.cpp
	$(CXX) $(CFLAGS) -o SeatingChartSlow -O2 SeatingChartSlow.cpp

SeatingChart.in: GenerateInput.py
	python GenerateInput.py > SeatingChart.in

SeatingChart.out: SeatingChart SeatingChart.in
	time ./SeatingChart < SeatingChart.in > SeatingChart.out

SeatingChart.class: SeatingChart.java
	javac SeatingChart.java

seating_chart_darthur: seating_chart_darthur.cpp
	$(CXX) $(CFLAGS) -o seating_chart_darthur seating_chart_darthur.cpp

clean:
	rm -f $(TARGETS) *.aux *.log SeatingChartSlow.out

test: all
	perl validate.pl < SeatingChart.in
	perl validate.pl < SeatingChart.sample.in
	time ./SeatingChart < SeatingChart.in > t.out
	diff t.out SeatingChart.out
	./SeatingChart < SeatingChart.sample.in > t.out
	diff t.out SeatingChart.sample.out

testall: all
	perl validate.pl < SeatingChart.in
	perl validate.pl < SeatingChart.sample.in
	time ./SeatingChart < SeatingChart.in > t.out
	diff t.out SeatingChart.out
	./SeatingChart < SeatingChart.sample.in > t.out
	diff t.out SeatingChart.sample.out
	time ./SeatingChartSlow < SeatingChart.in > t.out
	diff t.out SeatingChart.out
	time java $(JAVAOPTS) SeatingChart < SeatingChart.in > t.out
	diff t.out SeatingChart.out
	time ./seating_chart_darthur < SeatingChart.in > t.out
	diff t.out SeatingChart.out
