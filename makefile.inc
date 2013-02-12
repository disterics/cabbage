OS := $(shell uname)
#  executables
ECHO=echo
EMACS=emacs
EMACS_CC=$(EMACS) $(LIB_DIRS) $(OPTS)

OPTS=-batch -f batch-byte-compile
LIB_DIRS += -L .

all: subdirs elcs

destdirs: $(DESTDIRS)

elcs: $(ELCS)

files: $(FILES)

install-all: install
	-for d in $(SUBDIRS); do (cd $$d; $(MAKE) install-all ); done

install: all destdirs files

subdirs: $(SUBDIRS)

$(DESTDIRS):
	mkdir -p $@

$(FILES):
	install $@ $(DESTDIR)/$@

$(SRCS):
	install $@ $(DESTDIR)/$@

$(SUBDIRS):
	$(MAKE) -C $@

%.elc: %.el
	$(EMACS_CC) $<
# cp $< $(DESTDIR)/$<

clean:
	$(ECHO) cleaning up in .
	-$(RM) -f $(ELCS)
	-for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done


.PHONY: $(FILES) $(SUBDIRS) destdirs elcs files subdirs install install-all install-debug clean-install
