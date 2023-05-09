all: controllerTest.z64
.PHONY: all

BUILD_DIR = build
include $(N64_INST)/include/n64.mk

OBJS = $(BUILD_DIR)/controllerTest.o

controllerTest.z64: N64_ROM_TITLE = "Controller Test"

$(BUILD_DIR)/controllerTest.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
