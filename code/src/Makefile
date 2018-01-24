# Makefile

OUT=run_this_firmware

OBJDIR=build/
INCLUDE=include/

SRC = math.c main.c hw/i2c.c
OBJS = $(addprefix $(OBJDIR),$(SRC:.c=.o))

all: $(OBJDIR) $(OUT)

$(OUT): $(OBJS)
	gcc $^ -o $@
	
$(OBJDIR)%.o: %.c
	$(CC) -I$(INCLUDE) -c $^ -o $@

$(OBJDIR):
	mkdir -p $@
	mkdir -p $@/hw

clean:
	rm -rf $(OBJDIR) $(OUT)
