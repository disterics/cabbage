include common.inc

RSYNC := rsync
RSYNC_FILTERS := -f "+ */" -f "+ *.elc" -f "- *"
RSYNC_DEBUG_FILTERS := -f "+ */" -f "+ *.el" -f "- *"
RSYNC_OPTIONS := -am --delete --delete-excluded
RSYNC_OPTIONS := -am
CABBAGE_ROOT := $(EMACS.D)/cabbage

SRCS := cabbage.el
DESTDIR := $(EMACS.D)/cabbage
DESTDIRS = $(addprefix $(DESTDIR)/, $(SUBDIRS))

# compilation targets
SUBDIRS := lib bundles vendor
ELCS := $(SRCS:.el=.elc)

include makefile.inc

install: all destdirs files
	$(RSYNC) $(RSYNC_OPTIONS) $(RSYNC_FILTERS) . $(CABBAGE_ROOT)

install-debug:
	$(RSYNC) $(RSYNC_OPTIONS) $(RSYNC_DEBUG_FILTERS) . $(CABBAGE_ROOT)
