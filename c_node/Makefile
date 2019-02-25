######################################################################
# Copyright (c) 2019 Mathieu Kerjouan
#
# Permission to use, copy, modify, and distribute this software for
# any purpose with or without fee is hereby granted, provided that the
# above copyright notice and this permission notice appear in all
# copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
# WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
# AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
# DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA
# OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
# TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.
######################################################################
CC = /usr/bin/cc
MAKE = /usr/local/bin/gmake
ERL_RELEASE ?= 21
CC_DIRLIB = -L/usr/local/lib/erlang$(ERL_RELEASE)/usr/lib
CC_DIRINC = -I/usr/local/lib/erlang$(ERL_RELEASE)/usr/include
CC_LIBS = -lei -lerl_interface -lerts
CC_OPTS = -Wall -Wextra $(CC_DIRLIB) $(CC_DIRINC) $(CC_LIBS)
TARGETS = 

ifdef $(DEBUG)
CC_OPTS += -g
endif

.PHONY += all
all: bootstrap mono multi

.PHONY += debug
debug:
	$(MAKE) DEBUG=YES all

.PHONE += bootstrap
bootstrap:
	pkg_add erlang%$(ERL_RELEASE)

TARGETS += shared.o
shared.o:
	$(CC) $(CC_OPTS) -c shared.c -o $@

TARGETS += mono
mono: shared.o
	$(CC) $(CC_OPTS) mono.c shared.o -o $@

TARGETS += multi
multi: shared.o
	$(CC) $(CC_OPTS) -lpthread multi.c shared.o -o $@

.PHONE += clean
clean: 
	rm $(TARGETS)
