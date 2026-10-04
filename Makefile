# 指定编译器
CC = gcc
# 编译参数（开启所有警告，加上调试信息）
CFLAGS = -Wall -g
# 最终目标文件名
TARGET = my_app
# 要编译的源文件
SRCS = main.c uart.c
# 生成的目标文件（把.c替换成.o）
OBJS = $(SRCS:.c=.o)

# 默认目标：链接生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# 模式规则：如何把 .c 编译成 .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理规则：清理编译产生的中间文件
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标（防止目录里有同名文件干扰）
.PHONY: clean