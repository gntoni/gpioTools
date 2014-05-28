# locate the necessary dependencies
# add the necessary include directories
INCLUDE_DIRECTORIES(.)
# application source files
SET(sources gpiotools.cpp)
# application header files
SET(headers gpiotools.h)
# create the executable file
ADD_EXECUTABLE(gpiotools ${sources})
# link necessary libraries
