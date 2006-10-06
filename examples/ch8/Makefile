#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check


FILES_WITH_MAIN	= solution1.C solution2.C  solution3.C

TEMPLATE_INSTANCES = solution1_tinst.cc solution2_tinst.cc solution3_tinst.cc

SOURCE_FILES = Element.C Element3.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 
	    
# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
solution1: solution1.o solution1_tinst.o
	@echo Linking $@
	$(LINK) solution1.o solution1_tinst.o

solution2: solution2.o Element.o solution2_tinst.o
	@echo Linking $@
	$(LINK) solution2.o Element.o solution2_tinst.o

solution3: solution3.o Element3.o solution3_tinst.o
	@echo Linking $@
	$(LINK) solution3.o Element3.o solution3_tinst.o

clean:
	rm -f $(OBJ_FILES) 

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
	rm -rf Deps

#-include Deps/empty.d
Deps/empty.d:
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
	@echo Running solution1: ;  solution1 < input_for_sol123
	@echo Running solution2: ;  solution2 < input_for_sol123
	@echo Running solution3: ;  solution3 < input_for_sol123



