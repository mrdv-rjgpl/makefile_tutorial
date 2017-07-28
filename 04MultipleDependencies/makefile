#
# @brief: Simple makefile tutorial, with added clean command and multiple dependencies.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# In this example, we add multiple dependencies to the recipe for 'all'. Each recipe on which 'all' depends is
# executed only if required. This can be tested by using the command ` touch subtract_two_numbers.cpp ` after
# running the command ` make ` once.
#
all: add_two_numbers.exe subtract_two_numbers.exe

#
# The recipe for 'add_two_numbers.exe' remains the same as before.
#
add_two_numbers.exe: add_two_numbers.cpp
	g++ -o add_two_numbers.exe add_two_numbers.cpp

#
# The recipe for 'subtract_two_numbers.exe' is identical to the recipe for 'add_two_numbers.exe', with a
# dependency on the file 'subtract_two_numbers.cpp'.
#
subtract_two_numbers.exe: subtract_two_numbers.cpp
	g++ -o subtract_two_numbers.exe subtract_two_numbers.cpp

#
# The clean recipe is similar to the previous clean recipe, with the addition of subtract_two_numbers.exe.
#
clean:
	rm add_two_numbers.exe subtract_two_numbers.exe
