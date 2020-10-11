# This makefile was based on friedmud's answer to the following question
# https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile

appName     := TLib
buildDir    := BuildOutputs
relBuildDir := $(buildDir)/Release
dbgBuildDir := $(buildDir)/Debug

incDirs  := $(shell find . -type d)
incFlags := $(foreach dir, incDirs, -I$(dir))
srcFiles := $(shell find . -name "*.cpp")
objs     := $(patsubst %.cpp, %.o, $(srcFiles))

ldFlags :=
ldLibs  :=

cxx      := g++
cxxFlags := 
dbgFlags := -g

all: release

release: $(objs)
	mkdir -p $(relBuildDir)
	$(cxx) $(incFlags) $(cxxFlags) $(ldFlags) -o $(relBuildDir)/$(appName).out $(objs) $(ldLibs)

debug: $(objs)
	mkdir -p $(dbgBuildDir)
	$(cxx) $(incFlags) $(dbgFlags) $(cxxFlags) $(ldFlags) -o $(dbgBuildDir)/$(appName).out $(objs) $(ldLibs)

depend: .depend

.depend: $(srcFiles)
	rm -f ./.depend
	$(cxx) $(cxxFlags) -MM $^>>./.depend;

clean:
	rm -rf $(objs)
	rm -rf $(buildDir)/*

dist-clean: clean
	rm -f .depend

include .depend