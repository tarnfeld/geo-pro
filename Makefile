SHELL 		 :=		bash
PROJECT_NAME :=		geopro
VERSION		 :=		0.1.0
SRC_DIR	     :=		$(shell pwd)/src
BUILD_DIR	 :=     $(shell pwd)/build
BIN_PATH	 :=		$(BUILD_DIR)/$(PROJECT_NAME)-$(VERSION).bin
PATH		 := 	$(shell pwd)/node_modules/bin:$(PATH)

.PHONY: all
all: deps geopro

.PHONY: deps
deps:
	@which particle >/dev/null || npm install particle-cli

.PHONY: geopro
geopro: $(BIN_PATH)

.PHONY: clean
clean:
	rm -rf build/

SRC := $(shell find src -type f | grep -iE '.*(ino|h|c|cpp)')
$(BIN_PATH): $(SRC)
	mkdir -p build/
	particle compile photon $(SRC) --saveTo $(BIN_PATH)

.PHONY: dfu-flash
dfu-flash: geopro
	@echo "Ensure the particle is plugged in and in DFU mode..."
	@echo "    1) Press and hold both the RESET/RST and MODE/SETUP buttons simultaneously."
	@echo "    2) Release only the RESET/RST button while continuing to hold the MODE/SETUP button.."
	@echo "    3) Release the MODE/SETUP button once the device begins to blink yellow."
	@echo -n "Hit [ENTER] when you're ready..."
	@read
	particle flash --usb $(BIN_PATH)
