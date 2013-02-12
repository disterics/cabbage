include ../common.inc

LCL_DIRS := . bundles platforms
SRCS := $(foreach dir,$(LCL_DIRS),$(find_files))
DESTDIR := $(EMACS.D)/cabbage/lib
DESTDIRS := $(addprefix $(DESTDIR)/, $(LCL_DIRS))

# compilation targets
ELCS := $(SRCS:.el=.elc)

include ../makefile.inc
