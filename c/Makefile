CC = clang
CFLAGS = -Wall -Wextra -Werror

EX00_DIR = ex00
EX01_DIR = ex01
EX02_DIR = ex02

EX00_NAME = $(EX00_DIR)/Colleen
EX01_NAME = $(EX01_DIR)/Grace
EX02_NAME = $(EX02_DIR)/Sully

EX00_SRC = $(EX00_NAME).c
EX01_SRC = $(EX01_NAME).c
EX02_SRC = $(EX02_NAME).c

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
build: $(EX00_NAME) $(EX01_NAME) $(EX02_NAME) ## Builds the executables on each folder

.PHONY: clean
clean: ## deletes transitive dependencies
	@rm -f $(EX00_OBJS)
	@rm -f $(EX01_OBJS)
	@rm -f $(EX02_OBJS)
	@rm -f $(EX02_OBJ_DIR)_*.o

.PHONY: fclean 
fclean: clean ## deletes transitive dependencies + the executables
	@rm -f $(EX00_NAME)
	@rm -f $(EX01_NAME)
	@rm -f $(EX02_NAME)
	@rm -f $(EX02_NAME)_*.c

$(EX00_OBJ_DIR)/%.o: $(EX00_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(EX01_OBJ_DIR)/%.o: $(EX01_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(EX02_OBJ_DIR)/%.o: $(EX02_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(EX00_NAME): $(EX00_OBJS)
	$(CC) $(CFLAGS) $(EX00_OBJS) -o $(EX00_NAME)

$(EX01_NAME): $(EX01_OBJS)
	$(CC) $(CFLAGS) $(EX01_OBJS) -o $(EX01_NAME)

$(EX02_NAME): $(EX02_OBJS)
	$(CC) $(CFLAGS) $(EX02_OBJS) -o $(EX02_NAME)
