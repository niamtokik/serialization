# GNU Makefile
CC = /usr/bin/cc
MAKE = /usr/local/bin/gmake
ERL_RELEASE ?= 21
CC_DIRLIB = -L/usr/local/lib/erlang$(ERL_RELEASE)/usr/lib
CC_DIRINC = -I/usr/local/lib/erlang$(ERL_RELEASE)/usr/include
CC_LIBS = -lei -lerl_interface -lerts
CC_OPTS = -Wall -Wextra $(CC_DIRLIB) $(CC_DIRINC) $(CC_LIBS)
TARGETS = 
TARGETS_TEST = 

ifdef $(DEBUG)
CC_OPTS += -g
endif

######################################################################
#
######################################################################
.PHONY += help
help:
	@echo "\tbootstrap: install required package (OpenBSD)"
	@echo "\tall: build everything"
	@echo "\tdebug: build with debug flags"
	@echo "\ttest: build test code"
	@echo "\ttest-run: run test code"
	@echo "\tclean-all: clean everything"
	@echo "\tclean: clean standard build"
	@echo "\tclean-test: clean test build"

.PHONY += all
all: test mono multi

.PHONY += debug
debug:
	$(MAKE) DEBUG=YES all

.PHONY += bootstrap
bootstrap:
	pkg_add erlang%$(ERL_RELEASE)

######################################################################
# standard code
######################################################################
TARGETS += shared.o
shared.o:
	$(CC) $(CC_OPTS) -c shared.c -o $@

TARGETS += mono
mono: shared.o
	$(CC) $(CC_OPTS) mono.c shared.o -o $@

TARGETS += multi
multi: shared.o
	$(CC) $(CC_OPTS) -lpthread multi.c shared.o -o $@

######################################################################
# test code
######################################################################
TARGETS_TEST += shared_test
shared_test: shared.o
	$(CC) $(CC_OPTS) shared_test.c shared.o -o $@

TARGETS_TEST += mono_test
mono_test: shared.o
	$(CC) $(CC_OPTS) mono_test.c shared.o -o $@

TARGETS_TEST += multi_test
multi_test: shared.o
	$(CC) $(CC_OPTS) mono_test.c shared.o -o $@

.PHONY += test
test: $(TARGETS_TEST)

.PHONY += test-run
test-run:
	for i in $(TARGETS_TEST); do \
		./$${i}; \
	done

######################################################################
# clean feature
######################################################################
.PHONY += clean
clean: 
	rm $(TARGETS)

.PHONY += clean-test
clean-test:
	rm $(TARGETS_TEST)

.PHONY += clean-all
clean-all: clean clean-test
