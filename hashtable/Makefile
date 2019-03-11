#!/bin/bash

EXECUTABLE = hash_table

UTILITY_DIR = ..
UTILITY_SRC = $(wildcard $(UTILITY_DIR)/*.cc)

HASHTABLE_SRC = $(wildcard *.c)

OBJ_DIR = obj
OBJ_FILES = $(subst $(UTILITY_DIR), $(OBJ_DIR), $(patsubst %.cc, %.o, $(UTILITY_SRC)))
OBJ_FILES += $(patsubst %.cc, $(OBJ_DIR)/%.o, $(HASHTABLE_SRC))

CXXFLAGS += -I$(UTILITY_DIR)/

$(EXECUTABLE): obj_dir $(OBJ_FILES)
	@echo "Linking " $@
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(UTILITY_DIR)/%.cc
	@echo "Compiling " $@ "from " $^
	@$(CXX) $(CXXFLAGS) -c $^ -o $@
	
$(OBJ_DIR)/%.o: %.c
	@echo "Compiling " $@ "from " $^
	@$(CC) $(CXXFLAGS) -c $^ -o $@

obj_dir:
	@mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)
