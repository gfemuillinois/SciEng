include ../../SciEng.mkdefs-$(HOSTTYPE)

FILES_WITH_MAIN	= char-out.C const.C enum.C fortran-compatible-io.C funcarg.C io.C iodemo.C new.C refs.C regurgitate.C sqrtTable.C

ALL_FILES = char-out.C const.C doubleSqr.C enum.C ex-refs.C fortran-compatible-io.C funcarg.C io.C iodemo.C new.C ptrdclstyles.C refs.C regurgitate.C simplecpp.C sqrtTable.C vertstyle.C void.C

all:	$(ALL_FILES:.C=.o) $(FILES_WITH_MAIN:.C=)

clean:
	rm -f $(ALL_FILES:.C=.o)

real_clean: clean
	rm -f $(FILES_WITH_MAIN:.C=)
