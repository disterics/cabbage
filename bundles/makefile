include ../common.inc

# enabled bundles
BUNDLES := completion

SRCS := $(foreach dir,$(BUNDLES),$(find_files))
DESTDIR := $(EMACS.D)/cabbage/bundles
DESTDIRS := $(addprefix $(DESTDIR)/, $(BUNDLES))

# compilation targets
ELCS := $(SRCS:.el=.elc)

include ../makefile.inc
