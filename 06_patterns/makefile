#
# @brief: Simple makefile tutorial, with patterns used to make a single recipe.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# The recipe for all remains the same as before.
#
all: add_two_numbers.exe subtract_two_numbers.exe

#
# In the previous examples, we observed that the recipes for 'add_two_numbers.exe' and 'subtract_two_numbers.exe' were
# identical, with the exception of the file names involved. The make system allows us to create a single recipe
# for file pairs matching a given pattern, as below. This recipe is used for any file ending in '.exe', with a
# corresponding pre-requisite of the same file name (as given by '%'), with the file extension '.cpp'.
#
%.exe: %.cpp
	g++ -o $(@) $(<)

#
# The clean recipe is similar to the previous clean recipe, with the addition of subtract_two_numbers.exe.
#
clean:
	rm add_two_numbers.exe subtract_two_numbers.exe
