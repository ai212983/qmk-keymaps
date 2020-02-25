SRC += base.c \
	   common.c \
	   layers.c \
       shift_override.c \
       russian.c

CFLAGS += -DKEYSET_VERSION=\"$(KEYSET_VERSION)\"
CFLAGS += -DKEYSET_DATETIME=\"$(KEYSET_DATETIME)\"

NKRO_ENABLE       = yes
UNICODEMAP_ENABLE = yes
