#
# Creates SciEng.a and run make on al examples directories
#
# To create SciEng.a with templates implicitly instantiated do:
#
# make USE_IMPLICITY_TEMPL=YES SciEng.a
#
# make USE_IMPLICITY_TEMPL=YES SciEngMatx.a
#
# we recommend using the above until we are proved wrong....
# The difference in size between the YES/NO option for
# USE_IMPLICITY_TEMPL was only 200k  
#
# NOTE: Last time we used make, we did NOT use the options above.
# ====
#

HOSTTYPE = $(shell uname)
include  SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check clean_SciEng

## Command to remove a file
RM = /bin/rm

# We are using templates implicitly instantiated ALWAYS!
#	$(CXX) $(CXXTEMPLATE) -I. $(CXXFLAGS) -c $<  -o $*.o

(%.o) : %.C
	$(CXX) -DXLC_QNOTEMPINC -I. $(CXXFLAGS) -c $< -o $*.o 
	$(AR) rv $@ $*.o 
	$(RM) $*.o
	ranlib $@

all:	SciEng.a  SciEngMatx.a templ_instatiation_g++
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
	cd examples/ch12; $(MAKE) WERROR=
	cd examples/ch13; $(MAKE)
	cd examples/ch14; $(MAKE)
	cd examples/ch15; $(MAKE) 
	cd examples/ch16; $(MAKE) USE_IMPLICITY_TEMPL=YES
	cd examples/ch18; $(MAKE)
	cd LapackWrap;    $(MAKE) WERROR=
	cd Vector;        $(MAKE)
#	cd examples/ch17; $(MAKE)
#	cd examples/ch19; $(MAKE)

templ_instatiation_g++:
	ln -s examples/ch4/templ_instatiation_g++ .

SciEngMatx.a:	\
	SciEngMatx.a(SciEng/ArrayErr.o) \
	SciEngMatx.a(SciEng/Boolean.o) \
	SciEngMatx.a(SciEng/Fallible.o) \
	SciEngMatx.a(SciEng/NewHandler.o) \
	SciEngMatx.a(SciEng/SciEngEnvironment.o) \
	SciEngMatx.a(SciEng/SciEngErr.o) \
	SciEngMatx.a(SciEng/String.o) \
	SciEngMatx.a(SciEng/Terminate.o) \
	SciEngMatx.a(Array/ArrayShape.o) \
	SciEngMatx.a(Array/ConcreteFortranSymmetricPackedArray2d.o) \
	SciEngMatx.a(LapackWrap/BlasSubroutines.o) \
	SciEngMatx.a(LapackWrap/LapackErr.o) \
	SciEngMatx.a(Algebra/ComplexFloat.o) \
	SciEngMatx.a(Vector/ConcreteVector3d.o) \
	SciEngMatx.a(Vector/MisMatchedSizeErr.o)

SciEng.a:	\
	SciEng.a(SciEng/ArrayErr.o) \
	SciEng.a(SciEng/Boolean.o) \
	SciEng.a(SciEng/Fallible.o) \
	SciEng.a(SciEng/NewHandler.o) \
	SciEng.a(SciEng/SciEngEnvironment.o) \
	SciEng.a(SciEng/SciEngErr.o) \
	SciEng.a(SciEng/String.o) \
	SciEng.a(SciEng/Terminate.o) \
	SciEng.a(Array/ArrayShape.o) \
	SciEng.a(Array/ConcreteFortranSymmetricPackedArray2d.o) \
	SciEng.a(LapackWrap/BlasSubroutines.o) \
	SciEng.a(LapackWrap/LapackErr.o) \
	SciEng.a(Algebra/ComplexFloat.o) \
	SciEng.a(Units/Physical.o) \
	SciEng.a(DataModeling/GaussianDeviates.o) \
	SciEng.a(Function/Function.o) \
	SciEng.a(Vector/ConcreteVector3d.o) \
	SciEng.a(Vector/MisMatchedSizeErr.o)
#	SciEng.a(DataModeling/FormedPhysicalData.o) \

clean:
	rm -f SciEng/ArrayErr.o \
	SciEng/Boolean.o \
	SciEng/Fallible.o \
	SciEng/NewHandler.o \
	SciEng/SciEngEnvironment.o \
	SciEng/SciEngErr.o \
	SciEng/String.o \
	SciEng/Terminate.o \
	Array/ArrayShape.o \
	Array/ConcreteFortranSymmetricPackedArray2d.o \
	LapackWrap/BlasSubroutines.o \
	LapackWrap/LapackErr.o \
	Algebra/ComplexFloat.o \
	Units/Physical.o \
	DataModeling/FormedPhysicalData.o \
	DataModeling/GaussianDeviates.o \
	Function/Function.o \
	Vector/ConcreteVector3d.o \
	Vector/MisMatchedSizeErr.o
	rm -f SciEng.a 
	rm -f SciEngMatx.a
	cd examples/ch2; $(MAKE) clean
	cd examples/ch3; $(MAKE) clean
	cd examples/ch4; $(MAKE) clean
	cd examples/ch5; $(MAKE) clean
	cd examples/ch6; $(MAKE) clean
	cd examples/ch7; $(MAKE) clean
	cd examples/ch8; $(MAKE) clean
	cd examples/ch9; $(MAKE) clean
	cd examples/ch10; $(MAKE) clean
	cd examples/ch11; $(MAKE) clean
	cd examples/ch12; $(MAKE) clean
	cd examples/ch13; $(MAKE) clean
	cd examples/ch14; $(MAKE) clean
	cd examples/ch15; $(MAKE) clean
	cd examples/ch16; $(MAKE) clean
#	cd examples/ch17; $(MAKE) clean
	cd examples/ch18; $(MAKE) clean
#	cd examples/ch19; $(MAKE) clean
	cd LapackWrap;    $(MAKE) clean
	cd Vector;        $(MAKE) clean

real_clean:
	rm -f SciEng/ArrayErr.o \
	SciEng/Boolean.o \
	SciEng/Fallible.o \
	SciEng/NewHandler.o \
	SciEng/SciEngEnvironment.o \
	SciEng/SciEngErr.o \
	SciEng/String.o \
	SciEng/Terminate.o \
	Array/ArrayShape.o \
	Array/ConcreteFortranSymmetricPackedArray2d.o \
	LapackWrap/BlasSubroutines.o \
	LapackWrap/LapackErr.o \
	Algebra/ComplexFloat.o \
	Units/Physical.o \
	DataModeling/FormedPhysicalData.o \
	DataModeling/GaussianDeviates.o \
	Function/Function.o \
	Vector/ConcreteVector3d.o \
	Vector/MisMatchedSizeErr.o
	rm -f SciEng.a 
	rm -f SciEngMatx.a
	cd examples/ch2; $(MAKE) real_clean
	cd examples/ch3; $(MAKE) real_clean
	cd examples/ch4; $(MAKE) real_clean
	cd examples/ch5; $(MAKE) real_clean
	cd examples/ch6; $(MAKE) real_clean
	cd examples/ch7; $(MAKE) real_clean
	cd examples/ch8; $(MAKE) real_clean
	cd examples/ch9; $(MAKE) real_clean
	cd examples/ch10; $(MAKE) real_clean
	cd examples/ch11; $(MAKE) real_clean
	cd examples/ch12; $(MAKE) real_clean
	cd examples/ch13; $(MAKE) real_clean
	cd examples/ch14; $(MAKE) real_clean
	cd examples/ch15; $(MAKE) real_clean
	cd examples/ch16; $(MAKE) real_clean
#	cd examples/ch17; $(MAKE) real_clean
	cd examples/ch18; $(MAKE) real_clean
#	cd examples/ch19; $(MAKE) real_clean
	cd LapackWrap;    $(MAKE) real_clean
	cd Vector;        $(MAKE) real_clean

clean_SciEng:
	rm -f SciEng/ArrayErr.o \
	SciEng/Boolean.o \
	SciEng/Fallible.o \
	SciEng/NewHandler.o \
	SciEng/SciEngEnvironment.o \
	SciEng/SciEngErr.o \
	SciEng/String.o \
	SciEng/Terminate.o \
	Array/ArrayShape.o \
	Array/ConcreteFortranSymmetricPackedArray2d.o \
	LapackWrap/BlasSubroutines.o \
	LapackWrap/LapackErr.o \
	Algebra/ComplexFloat.o \
	Units/Physical.o \
	DataModeling/FormedPhysicalData.o \
	DataModeling/GaussianDeviates.o \
	Function/Function.o \
	Vector/ConcreteVector3d.o \
	Vector/MisMatchedSizeErr.o
	rm -f SciEng.a	
	rm -f SciEngMatx.a

check:
	@echo HOSTTYPE: $(HOSTTYPE)
	@echo CXX,CC,LD: $(CXX) : $(CC) : $(LD)
	@echo OPT: $(OPT)
	@echo OPTM: $(OPTM)

# The sequence of runs will stop if any executable 
# returns non-zero value.
run_all:
	@echo Running examples/ch2;  cd examples/ch2;  $(MAKE) run_all
	@echo Running examples/ch3;  cd examples/ch3;  $(MAKE) run_all
	@echo Running examples/ch4;  cd examples/ch4;  $(MAKE) run_all
	@echo Running examples/ch5;  cd examples/ch5;  $(MAKE) run_all
	@echo Running examples/ch6;  cd examples/ch6;  $(MAKE) run_all
	@echo Running examples/ch7;  cd examples/ch7;  $(MAKE) run_all
	@echo Running examples/ch8;  cd examples/ch8;  $(MAKE) run_all
	@echo Running examples/ch9;  cd examples/ch9;  $(MAKE) run_all
	@echo Running examples/ch10;  cd examples/ch10;  $(MAKE) run_all
	@echo Running examples/ch11;  cd examples/ch11;  $(MAKE) run_all
	@echo Running examples/ch12;  cd examples/ch12;  $(MAKE) run_all
	@echo Running examples/ch13;  cd examples/ch13;  $(MAKE) run_all
	@echo Running examples/ch14;  cd examples/ch14;  $(MAKE) run_all
	@echo Running examples/ch15;  cd examples/ch15;  $(MAKE) run_all
	@echo Running examples/ch16;  cd examples/ch16;  $(MAKE) run_all
	@echo Running examples/ch18;  cd examples/ch18; $(MAKE) run_all
	@echo Running LapackWrap;     cd LapackWrap;    $(MAKE) run_all
	@echo Running Vector;         cd Vector;        $(MAKE) run_all



