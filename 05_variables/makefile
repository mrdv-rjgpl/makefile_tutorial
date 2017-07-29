#
# @brief: Simple makefile tutorial, with variables used in commands.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# The recipe for all remains the same as before.
#
all: add_two_numbers.exe subtract_two_numbers.exe

#
# The recipe for 'add_two_numbers.exe' now has variables added to it, $(@) for the target name 'add_two_numbers.exe'
# and $(<) for the first pre-requisite 'add_two_numbers.cpp'.
#
add_two_numbers.exe: add_two_numbers.cpp
	g++ -o $(@) $(<)

#
# The recipe for 'subtract_two_numbers.exe' is similar to the recipe for 'add_two_numbers.exe'
#
subtract_two_numbers.exe: subtract_two_numbers.cpp
	g++ -o $(@) $(<)

#
# The clean recipe is similar to the previous clean recipe, with the addition of subtract_two_numbers.exe.
#
clean:
	rm add_two_numbers.exe subtract_two_numbers.exe
