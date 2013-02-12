EMACS.D := ~/.emacs.d

# function to find el file given a directory
find_files = $(wildcard $(dir)/*.el)
