#
#
HOSTTYPE = $(shell uname)-$(shell uname -m)
include ../../SciEng.mkdefs-$(HOSTTYPE)

.PHONY: all clean real_clean run_all check

FILES_WITH_MAIN	= char-out.C const.C enum.C fortran-compatible-io.C \
	funcarg.C io.C iodemo.C new.C refs.C regurgitate.C sqrtTable.C

ALL_FILES = char-out.C const.C doubleSqr.C enum.C ex-refs.C \
	fortran-compatible-io.C funcarg.C io.C iodemo.C new.C \
	ptrdclstyles.C refs.C regurgitate.C simplecpp.C sqrtTable.C \
	vertstyle.C void.C

#Automatically generated dependencies for .C and .cc files
DEPENDLIST = $(ALL_FILES:%.C=Deps/%.d)

# Targets:

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

clean:
	rm -f $(ALL_FILES:.C=.o)

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
	@echo Running char-out: ; char-out 
	@echo Running const: ; const < input_for_const
	@echo Running enum: ;  enum
	@echo Running fortran-compatible-io: ;  fortran-compatible-io
	@echo Running funcarg: ;  funcarg
	@echo Running io: ;  io
	@echo Running iodemo: ;  iodemo < input_for_iodemo
	@echo Running new: ;  new < input_for_new
	@echo Running refs: ;  refs
	@echo Running regurgitate: ;  regurgitate < input_for_regurgitate
	@echo Running sqrtTable: ;  sqrtTable < input_for_sqrtTable

