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
# One requirement, when making a generic makefile, is to make the individual recipes independent of the
# target name and pre-requisites involved. To aid in this, most make systems provide a number of automatic variables
# to be used inside a recipe. The contents of a variable 'v' can be accessed with the string '$(v)'.
#
# With that in mind, the recipe for 'add_two_numbers.exe' is modified to use automatic variables, $(@) for the target
# name 'add_two_numbers.exe', and $(<) for the first pre-requisite 'add_two_numbers.cpp'.
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
