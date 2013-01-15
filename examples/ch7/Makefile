#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= cache.C mixedNesting.C newDemo.C  \
	tAutoException.C tAutoNesting.C tDynLifetime.C \
	tStaticNesting.C zero.C static-linkage.C

TEMPLATE_INSTANCES = 

SOURCE_FILES = Dangle.C Rational.C Rational1.C RationalComplex.C \
	TraceLifetime.C  class-scope.C dangle0.C mixedNesting.C \
	 resource-acq.C static-linkage.C 

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(SOURCE_FILES:%.C=Deps/%.d) \
	     $(FILES_WITH_MAIN:%.C=Deps/%.d) \
	     $(TEMPLATE_INSTANCES:%.cc=Deps/%.d)

ALL_FILES = $(FILES_WITH_MAIN)  $(SOURCE_FILES)  $(TEMPLATE_INSTANCES)

OBJ_FILES = $(FILES_WITH_MAIN:.C=.o) $(SOURCE_FILES:.C=.o) $(TEMPLATE_INSTANCES:.cc=.o) 


# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

mixedNesting:	mixedNesting.o TraceLifetime.o
		@echo Linking $@
		$(LINK) mixedNesting.o TraceLifetime.o

tDynLifetime:	tDynLifetime.o TraceLifetime.o
		@echo Linking $@
		$(LINK) tDynLifetime.o TraceLifetime.o

tAutoException:	tAutoException.o TraceLifetime.o
		@echo Linking $@
		$(LINK) tAutoException.o TraceLifetime.o

tAutoNesting:	tAutoNesting.o TraceLifetime.o
		@echo Linking $@
		$(LINK) tAutoNesting.o TraceLifetime.o

tStaticNesting:	tStaticNesting.o TraceLifetime.o
		@echo Linking $@
		$(LINK) tStaticNesting.o TraceLifetime.o

zero:		zero.o
		@echo Linking $@
		$(LINK) zero.o $(COMPLEXLIB)
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
	@echo Running cache: ;  cache
	@echo Running mixedNesting: ;  mixedNesting
	@echo Running newDemo: ;  newDemo < input_for_newDemo
	@echo Running static-linkage: ;  static-linkage
	@echo Running tAutoException: ;  tAutoException
	@echo Running tAutoNesting: ;  tAutoNesting
	@echo Running tDynLifetime: ;  tDynLifetime
	@echo Running tStaticNesting: ;  tStaticNesting
	@echo Running zero: ;  zero
