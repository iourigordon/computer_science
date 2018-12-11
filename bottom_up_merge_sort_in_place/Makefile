#!/bin/bash

EXECUTABLE = bottom_up_merge_sort_in_place

UTILITY_DIR = ..
UTILITY_SRC = $(wildcard $(UTILITY_DIR)/*.cc)

INSERTION_SRC = $(wildcard *.cc)

OBJ_DIR = obj
OBJ_FILES = $(subst $(UTILITY_DIR), $(OBJ_DIR), $(patsubst %.cc, %.o, $(UTILITY_SRC)))
OBJ_FILES += $(patsubst %.cc, $(OBJ_DIR)/%.o, $(INSERTION_SRC))

CXXFLAGS += -I$(UTILITY_DIR)/ 

$(EXECUTABLE): obj_dir $(OBJ_FILES)
	@echo "Linking " $@
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(UTILITY_DIR)/%.cc
	@echo "Compiling " $@ "from " $^
	@$(CXX) $(CXXFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/%.o: %.cc
	@echo "Compiling " $@ "from " $^
	@$(CXX) $(CXXFLAGS) -c $^ -o $@

obj_dir:
	@mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)
