################################################################################
# GBA Makefile
################################################################################

# Name of the output (uses current folder name)
TARGET     := $(notdir $(CURDIR))

# Directory for intermediate and final build artifacts
BUILD      := build

# Directories containing source files (.c, .cpp, .s)
SOURCES    := source

# Directories containing public headers
INCLUDES   := include

# Directories containing binary data to embed
DATA       := data

# Pull in devkitPro’s common build rules for GBA
include $(DEVKITPRO)/examples/gba/template/common_rules
