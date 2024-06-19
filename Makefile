CXX = clang++
CXXFLAGS = -std=c++2b
INSTALL = install
INSTALL_DATA = $(INSTALL) -m 644

prefix := /usr/local
includedir := $(prefix)/include

SOURCES := $(wildcard src/*.hpp src/*/*.hpp src/*/*/*.hpp)
VERSION := $(shell cat VERSION)

all: $(SOURCES)

check: $(SOURCES)
	$(CXX) -fsyntax-only $(CXXFLAGS) $<

install: installdirs $(SOURCES)
	$(INSTALL_DATA) src/know.hpp $(DESTDIR)$(includedir)/
	$(INSTALL_DATA) src/know/*.hpp $(DESTDIR)$(includedir)/know/
	$(INSTALL_DATA) src/know/classes/*.hpp $(DESTDIR)$(includedir)/know/classes/

installdirs:
	$(INSTALL) -d $(DESTDIR)$(includedir)/
	$(INSTALL) -d $(DESTDIR)$(includedir)/know
	$(INSTALL) -d $(DESTDIR)$(includedir)/know/classes

uninstall:
	rm -f $(DESTDIR)$(includedir)/know.hpp
	rm -f $(DESTDIR)$(includedir)/know/classes.hpp
	rm -f $(DESTDIR)$(includedir)/know/classes/*.hpp

clean:
	@rm -f *~

distclean: clean

mostlyclean: clean

maintainer-clean: clean

.PHONY: all check install uninstall
.PHONY: clean distclean mostlyclean maintainer-clean
.SECONDARY:
.SUFFIXES:
