# This makefile was based on friedmud's answer to the following question
# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile

appname  := TGL
builddir := BuildOutputs

LDFLAGS :=
LDLIBS  :=

incdirs  := $(shell find . -type d)
incflags := $(foreach dir, incdirs, -I$(dir))
srcfiles := $(shell find . -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

CXX      := g++
CXXFLAGS := -g -pthread $(incflags) # sometimes need -lpthread instead

all: $(appname)

$(appname): $(objects)
	mkdir -p $(builddir)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(builddir)/$(appname).out $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -rf $(objects)
	rm -rf $(builddir)/*

dist-clean: clean
	rm -f .depend

include .depend