
.PHONY: all clean
objects: \
	null_pointer \
	signed_int_mul_overflow \
	signed_int_underflow \
	unsigned_int_mul_overflow \
	casting \
	promotions \
	signed_int_neg_underflow \
	sizeof \
	unsigned_int_overflow \
	initialize_variables \
  	signed_int_div_underflow \
	signed_int_overflow \
	unsigned_int_underflow

all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm `find . -executable` 2>/dev/null

