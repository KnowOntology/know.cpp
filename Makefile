CXX = clang++
CXXFLAGS = -std=c++2b
INSTALL = install
INSTALL_DATA = $(INSTALL) -m 644
VERSION = $(shell cat VERSION)

prefix := /usr/local
includedir := $(prefix)/include

all: src/know.hpp

check: src/know.hpp
	$(CXX) -fsyntax-only $(CXXFLAGS) $<

install: src/know.hpp
	mkdir -p $(DESTDIR)$(includedir)/
	$(INSTALL_DATA) $^ $(DESTDIR)$(includedir)/

uninstall:
	rm -f $(DESTDIR)$(includedir)/know.hpp

clean:
	@rm -f *~

distclean: clean

mostlyclean: clean

maintainer-clean: clean

.PHONY: all check install uninstall
.PHONY: clean distclean mostlyclean maintainer-clean
.SECONDARY:
.SUFFIXES:
