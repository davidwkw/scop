NAME = scop

SRC_DIR = srcs

BUILD_DIR = objs

SRCS = $(shell find $(SRC_DIR) -name '*.cpp' -not -path "$(SRC_DIR)/.git/*")

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

DEPENDENCIES_PATH = dependencies

ifeq ($(OS),Windows_NT)
    # If the OS is Windows
	VULKAN_SDK_PATH = C:\VulkanSDK\1.3.268.0
	VULKAN_SDK_LIBRARY_PATH = $(VULKAN_SDK_PATH)/lib
    GLFW_PATH = $(DEPENDENCIES_PATH)/glfw-3.3.9.bin.WIN64
	GLFW_LIBRARY_PATH = $(GLFW_PATH)/lib-vc2022
# else
#     UNAME_S := $(shell uname -s)
#     ifeq ($(UNAME_S),Linux)
#         # If the OS is Linux
#         GLFW_PATH = linux_value
#     endif
#     ifeq ($(UNAME_S),Darwin)
#         # If the OS is macOS
#         GLFW_PATH = macos_value
#     endif
endif

CXX = g++

CPPFLAGS :=  -I$(VULKAN_SDK_PATH)/include -Iinclude -I$(GLFW_PATH)/include $(INC_FLAGS) -MMD -MP 

RM = rm

all : $(NAME)

$(NAME)	:	$(OBJS)
	@echo "Creating $(NAME)"
	$(CXX) -fsanitize=address $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) -rf $(BUILD_DIR)

fclean : clean
	@$(RM) -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEPS)
