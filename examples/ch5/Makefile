#
HOSTTYPE = $(shell uname)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check


FILES_WITH_MAIN	=   args.C arrayArg.C con-callbr.C expdev.C resolve.C \
		 swap.C   wrong2.C  taxpy.C  
#                  abs.C taxpy1.C abstemp.C

TEMPLATE_INSTANCES =  args_tinst.cc \
		resolve_tinst.cc \
                taxpy_tinst.cc 
#                abs_tinst.cc taxpy1_tinst.cc

SOURCE_FILES = blastemp.C  dot.C hasVal.C logof.C  retdcl.C wrong1.C  dcldef.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

# Executables built from more than one object go here:
taxpy1:	taxpy1.o  taxpy1_tinst.o $(SCIENGLIB)
	$(LINK) taxpy1.o  taxpy1_tinst.o $(COMPLEXLIB) $(SCIENGLIB)

# Executables built from more than one object go here:
taxpy: 	taxpy.o  taxpy_tinst.o $(SCIENGLIB)
	$(LINK) taxpy.o  taxpy_tinst.o $(COMPLEXLIB) $(SCIENGLIB)

# Executables built from more than one object go here:
abs:	abs.o abs_tinst.o
	$(LINK) abs.o abs_tinst.o -lstdc++

# Executables built from more than one object go here:
args: args.o args_tinst.o
	$(LINK) args.o args_tinst.o $(SCIENGLIB)

# Executables built from more than one object go here:
resolve: resolve.o resolve_tinst.o
	$(LINK) resolve.o resolve_tinst.o

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
#	@echo Running abs: ;  abs
#	@echo Running abstemp: ;  abstemp
	@echo Running args: ;  args
	@echo Running arrayArg: ;  arrayArg
	@echo Running con-callbr: ;  con-callbr
	@echo Running expdev: ;   expdev
	@echo Running resolve: ;  resolve
	@echo Running swap: ;  swap
	@echo Running taxpy: ;  taxpy
	@echo Running taxpy1: ;  taxpy1
	@echo Running wrong2: ;  wrong2
