CC = clang
CFLAGS = -Wall -Wextra -Werror

EX00_DIR = ex00
EX01_DIR = ex01
EX02_DIR = ex02

EX00_NAME = Colleen
EX01_NAME = Grace
EX02_NAME = Sully

EX00_BIN = $(EX00_DIR)/$(EX00_NAME)
EX01_BIN = $(EX01_DIR)/$(EX01_NAME)
EX02_BIN = $(EX02_DIR)/$(EX02_NAME)

EX00_SRC = $(EX00_DIR)/$(EX00_NAME).c
EX01_SRC = $(EX01_DIR)/$(EX01_NAME).c
EX02_SRC = $(EX02_DIR)/$(EX02_NAME).c

EX00_OBJ_DIR  = $(EX00_DIR)/obj
EX01_OBJ_DIR  = $(EX01_DIR)/obj
EX02_OBJ_DIR  = $(EX02_DIR)/obj

EX00_OBJS  = $(patsubst $(EX00_DIR)/%.c, $(EX00_OBJ_DIR)/%.o, $(EX00_SRC))
EX01_OBJS  = $(patsubst $(EX01_DIR)/%.c, $(EX01_OBJ_DIR)/%.o, $(EX01_SRC))
EX02_OBJS  = $(patsubst $(EX02_DIR)/%.c, $(EX02_OBJ_DIR)/%.o, $(EX02_SRC))

.PHONY: all
all: help

.PHONY: help
help: ## Prints help for targets with comments
	@echo "Available Rules:"
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: build
build: $(EX00_BIN) $(EX01_BIN) $(EX02_BIN) ## Builds the executables on each folder

.PHONY: clean
clean: ## Deletes transitive dependencies
	@rm -f $(EX00_OBJS)
	@rm -f $(EX01_OBJS)
	@rm -f $(EX02_OBJS)
	@rm -f $(EX02_OBJ_DIR)/_*.o

.PHONY: fclean 
fclean: clean ## Deletes transitive dependencies + the executables
	@rm -f $(EX00_BIN)
	@rm -f $(EX01_BIN)
	@rm -f $(EX01_DIR)/Grace_kid.c
	@rm -f $(EX02_BIN)
	@rm -f $(EX02_BIN)_*

.PHONY: test00
test00: $(EX00_BIN) ## Build and Test the exercise 00
	cd $(EX00_DIR) && ./$(EX00_NAME) > bin_output && cat $(EX00_NAME).c > cat_output;
	cd $(EX00_DIR) && diff cat_output bin_output && echo "Não tem diferença entre eles yipiiiiiii"
	@cd $(EX00_DIR) && rm -f bin_output cat_output

.PHONY: test01
test01: $(EX01_BIN) ## Build and Test the exercise 01
	cd $(EX01_DIR) && ./$(EX01_NAME) && diff $(EX01_NAME).c Grace_kid.c && echo "Não tem diferença de novo yipiiiii"

.PHONY: test02
test02: $(EX02_BIN) ## Build and Test the exercise 02
	cd $(EX02_DIR) && ./$(EX02_NAME) && ls -al | grep $(EX02_NAME) | wc -l && echo "Se o output foi 13, tá igual o do pdf <3"

$(EX00_OBJ_DIR)/%.o: $(EX00_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(EX01_OBJ_DIR)/%.o: $(EX01_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(EX02_OBJ_DIR)/%.o: $(EX02_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(EX00_BIN): $(EX00_OBJS)
	@$(CC) $(CFLAGS) $(EX00_OBJS) -o $(EX00_BIN)

$(EX01_BIN): $(EX01_OBJS)
	@$(CC) $(CFLAGS) $(EX01_OBJS) -o $(EX01_BIN)

$(EX02_BIN): $(EX02_OBJS)
	@$(CC) $(CFLAGS) $(EX02_OBJS) -o $(EX02_BIN)
