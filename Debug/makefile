################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Student_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lab9rebalance

# Tool invocations
lab9rebalance: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
#	g++  -o "lab9rebalance" $(OBJS) $(USER_OBJS) $(LIBS)
	g++ -g -Wall -std=c++14 -o "dont_run_me" /home/msivraj/Documents/semester3/cs235/lab9rebalance/Student_Code/Node.cpp /home/msivraj/Documents/semester3/cs235/lab9rebalance/Student_Code/AVLTree.cpp /home/msivraj/Documents/semester3/cs235/lab9rebalance/Student_Code/Factory.cpp /home/msivraj/Documents/semester3/cs235/lab9rebalance/ignoreme.a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) lab9rebalance
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
