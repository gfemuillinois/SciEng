include SciEng.mkdefs

## Command to remove a file
RM = /bin/rm

.SUFFIXES:
.SUFFIXES:	.C .o .a

.C.a:
	$(CXX) $(CXXTEMPLATE) -I. $(CXXFLAGS) -c $<  -o $*.o
	$(AR) r $@ $*.o
	$(RM) $*.o

all:	SciEng.a 
	cd examples/ch2; $(MAKE)
	cd examples/ch3; $(MAKE)
	cd examples/ch4; $(MAKE)
	cd examples/ch5; $(MAKE)
	cd examples/ch6; $(MAKE)
	cd examples/ch7; $(MAKE)
	cd examples/ch8; $(MAKE)
	cd examples/ch9; $(MAKE)
	cd examples/ch10; $(MAKE)
	cd examples/ch11; $(MAKE)
	cd examples/ch12; $(MAKE)
	cd examples/ch13; $(MAKE)
	cd examples/ch14; $(MAKE)
	cd examples/ch15; $(MAKE)
	cd examples/ch16; $(MAKE)
	cd examples/ch17; $(MAKE)
	cd examples/ch18; $(MAKE)
	cd examples/ch19; $(MAKE)

SciEng.a:	\
SciEng.a(Algebra/ComplexFloat.o) SciEng.a(Array/ArrayShape.o) SciEng.a(Array/ConcreteFortranSymmetricPackedArray2d.o) SciEng.a(DataModeling/FormedPhysicalData.o) SciEng.a(DataModeling/GaussianDeviates.o) SciEng.a(Function/Function.o) SciEng.a(LapackWrap/BlasSubroutines.o) SciEng.a(LapackWrap/LapackErr.o) SciEng.a(SciEng/ArrayErr.o) SciEng.a(SciEng/Boolean.o) SciEng.a(SciEng/Fallible.o) SciEng.a(SciEng/NewHandler.o) SciEng.a(SciEng/SciEngEnvironment.o) SciEng.a(SciEng/SciEngErr.o) SciEng.a(SciEng/String.o) SciEng.a(SciEng/Terminate.o) SciEng.a(Units/Physical.o) SciEng.a(Vector/ConcreteVector3d.o) SciEng.a(Vector/MisMatchedSizeErr.o)
