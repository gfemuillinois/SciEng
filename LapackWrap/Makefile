#
#
HOSTTYPE = $(shell uname)
include ../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check


FILES_WITH_MAIN	= timeConcreteBlas1d.C timeConcreteBlas2d.C

TEMPLATE_INSTANCES = timeConcreteBlas1d_tinst.cc timeConcreteBlas2d_tinst.cc

SOURCE_FILES =  timer.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES =  $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o)

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
timeConcreteBlas1d :  timeConcreteBlas1d.o timer.o timeConcreteBlas1d_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	 timeConcreteBlas1d.o timer.o timeConcreteBlas1d_tinst.o $(SCIENGMATXLIB) $(LIBSYS)

timeConcreteBlas2d :  timeConcreteBlas2d.o timer.o timeConcreteBlas2d_tinst.o $(SCIENGMATXLIB)
	@echo Linking $@
	$(LINK)	 timeConcreteBlas2d.o timer.o timeConcreteBlas2d_tinst.o $(SCIENGMATXLIB) $(LIBSYS)

clarch.h:
	ln -s ../../util++_ut/util/clarch.h .

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps
	rm -rf docs/ConcreteBlas
	rm -f core

#docs:
# doxygen .... TBD

#-include Deps/empty.d
Deps/empty.d: clarch.h
	test -d Deps || mkdir Deps
	touch $@

$(DEPENDLIST): Deps/empty.d

#Automatically generated dependencies for .C and .cc files
-include $(DEPENDLIST)

check:
	@echo HOSTTYPE: $(HOSTTYPE)
	@echo CXX,CC,LD: $(CXX) : $(CC) : $(LD)
	@echo OPT: $(OPT)
	@echo OPTM: $(OPTM)
	@echo ALL_FILES: $(ALL_FILES)
	@echo
	@echo OBJ_FILES: $(OBJ_FILES)
	@echo
	@echo DEPENDLIST: $(DEPENDLIST)

# The sequence of runs will stop if any executable 
# returns non-zero value.
run_all:
	@echo Running timeConcreteBlas1d: ; timeConcreteBlas1d
	@echo Running timeConcreteBlas2d: ; timeConcreteBlas2d
