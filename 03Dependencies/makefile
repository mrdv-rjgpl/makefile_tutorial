#
# @brief: Simple makefile tutorial, with added clean command and dependencies.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# In the previous examples, it is observed that the compilation of the executable takes place each time the command
# ` make ` is called from the command line, regardless of whether the executable already exists or not. However, in
# larger repositories, it is desired to compile only those files which need to be compiled, and leave untouched
# whatever can be left so. Hence, the concept of a dependency. A dependency can be a file, or another recipe, or both.
# In most cases, each recipe is set up such that its execution results in the creation of a file whose name matches the
# label of the recipe. This is done so that the make system can check the timestamp of the file to determine whether the
# recipe should be executed in subsequent make command executions.
#
# In this example, we add the recipe for add_two_numbers.exe as a dependency to the recipe 'all'. The make command will
# execute the recipe labelled 'all' only after executing (if required) the recipe labelled 'add_two_numbers.exe'.
#
all: add_two_numbers.exe

#
# The recipe for 'add_two_numbers.exe' is identical to the recipe for 'all' in the previous examples, with the
# addition of a dependency on the code file. This recipe is required to be executed only when the code file is changed,
# and should fail if the corresponding code file does not exist. The make system can take care of these requirements if
# the code file add_two_numbers.cpp is added as a dependency to add_two_numbers.exe.
#
add_two_numbers.exe: add_two_numbers.cpp
	g++ -o add_two_numbers.exe add_two_numbers.cpp

#
# The clean command remains the same as before, as it is expected to run the same, regardless of the state of the
# repository.
#
clean:
	rm add_two_numbers.exe
