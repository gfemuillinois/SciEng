#
#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	=  arrayAssign.C Bool-examples.C  demoList.C
#                  demoFal.C

TEMPLATE_INSTANCES = 
#                  demoFal_tinst.cc

SOURCE_FILES =  Circle.C CmplxFlt.C SimpleFloatArray.C UsePoint.C \
                ambig-convert.C ambig-convert2.C ambig-convert3.C  \
	        cmplx.C cmplx1.C cmplx2.C dcl-syntax.C  friend.C \
		mult-assign.C SimpleArray.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 
	    
# Targets:

all:    $(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
demoFal : demoFal.o demoFal_tinst.o
	@echo Linking $@
	$(LINK) demoFal.o demoFal_tinst.o

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
#	@echo Running demoFal: ; demoFal
	@echo Running Bool-examples: ; Bool-examples
	@echo Running arrayAssign: ; arrayAssign

# Trying to automate the above....
NOT_TO_RUN = demoList

TO_RUN = $(filter-out $(NOT_TO_RUN), $(FILES_WITH_MAIN:.C=)) 

run_all2:
	$(foreach CODE,$(TO_RUN), $(SHELL) -ec $(CODE); )

#	$(foreach CODE,$(TO_RUN), $(SHELL) -ec echo Running $(CODE): ; $(SHELL) -ec '$(CODE)'; ) 




