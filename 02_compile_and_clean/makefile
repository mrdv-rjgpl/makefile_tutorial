#
# @brief: Simple makefile tutorial, with added clean command.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# Below is a recipe, or a list of statements to be executed when a certain command is called.
# The recipe has the name 'all'. Most makefiles contain a recipe labelled 'all', which is the recipe executed upon
# calling the command ` make `.
#
# The recipe below is simple enough to use over the alternative of typing in the corresponding g++ command in the
# terminal. However, there are several improvements that can be made to it.
#
# I use the extension '.exe' even though this is meant for a Linux system, as a simple way to distinguish executables
# from other types of files.
#
all:
	g++ -o add_two_numbers.exe add_two_numbers.cpp

#
# To this, we now add an explicit recipe to clean the folder of all auto-generated files, and leave only the code.
# This recipe has the name 'clean', and can be called from the command line with the command ` make clean `. Most
# good makefiles contain the two recipes 'all' and 'clean', in addition to several others.
#
clean:
	rm add_two_numbers.exe
