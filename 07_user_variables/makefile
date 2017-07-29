#
# @brief: Simple makefile tutorial, with user defined variables.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# In the previous examples, we observe that the executable file names are present in two different places,
# once as pre-requisites to the recipe 'all', and the second time inside the recipe 'clean'. This makes the
# maintenance of the makefile rather difficult, in the event of the addition or removal of code files. The first step
# to solving this problem is to create our own variable exe_file_names, which expands to the executable file names.
# This variable is then called wherever the executable file names are to be listed out.
#
exe_file_names = add_two_numbers.exe subtract_two_numbers.exe

#
# The recipe for all now uses the variable exe_file_names.
#
all: $(exe_file_names)

#
# The recipe for executable file generation remains the same as before.
#
%.exe: %.cpp
	g++ -o $(@) $(<)

#
# The clean recipe now uses the defined variable exe_file_names.
#
clean:
	rm $(exe_file_names)
