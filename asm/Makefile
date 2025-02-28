NASM = nasm
NFLAGS = -f elf64
CC = clang
CFLAGS = -Wall -Wextra -Werror

EX00_DIR = ex00
EX00_NAME = Colleen
EX00_BIN = $(EX00_DIR)/$(EX00_NAME)
EX00_SRC = $(EX00_DIR)/$(EX00_NAME).s
EX00_OBJ_DIR  = $(EX00_DIR)/obj
EX00_OBJS  = $(patsubst $(EX00_DIR)/%.s, $(EX00_OBJ_DIR)/%.o, $(EX00_SRC))


.PHONY: all
all: help

.PHONY: help
help: ## Prints help for targets with comments
	@echo "Available Rules:"
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: build
build: $(EX00_BIN) ## Builds the executables on each folder

.PHONY: clean
clean: ## Deletes transitive dependencies
	@rm -f $(EX00_OBJS)

.PHONY: fclean 
fclean: clean ## Deletes transitive dependencies + the executables
	@rm -f $(EX00_BIN)

.PHONY: re
re: fclean build ## Runs fclean + build

.PHONY: test00
test00: $(EX00_BIN) ## Build and Test the exercise 00
	cd $(EX00_DIR) && ./$(EX00_NAME) > bin_output && cat $(EX00_NAME).s > cat_output;
	cd $(EX00_DIR) && diff cat_output bin_output && echo "Não tem diferença entre eles yipiiiiiii"
	@cd $(EX00_DIR) && rm -f bin_output cat_output


$(EX00_OBJ_DIR)/%.o: $(EX00_DIR)/%.s
	@$(NASM) $(NFLAGS) $< -o $@

$(EX00_BIN): $(EX00_OBJS)
	@$(CC) $(CFLAGS) $(EX00_OBJS) -o $(EX00_BIN)
