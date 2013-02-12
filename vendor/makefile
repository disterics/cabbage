include ../common.inc

# core packages
CORE_PKGS := color-theme flymake-point mode-compile perspective theme-roller
# packages that i am using
USER_PKGS :=
PKGS := $(CORE_PKGS) $(USER_PKGS)
FILE_DIRS := theme-roller/themes
LCL_DIRS := $(PKGS) $(FILE_DIRS)

SRCS := $(foreach dir,$(PKGS),$(find_files))
DESTDIR := $(EMACS.D)/cabbage/vendor
DESTDIRS := $(addprefix $(DESTDIR)/, $(LCL_DIRS))

LIB_DIRS := -L color-theme -L theme-roller

# compilation targets
ELCS := $(SRCS:.el=.elc)
FILES = $(foreach dir,$(FILE_DIRS),$(find_files))

include ../makefile.inc
