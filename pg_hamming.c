#include <postgres.h>
#include <fmgr.h>

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(hamming_distance);


inline char count_nonzero_bits(char);


Datum
hamming_distance(PG_FUNCTION_ARGS)
{
    bytea * arg0 = PG_GETARG_BYTEA_PP(0);
    bytea * arg1 = PG_GETARG_BYTEA_PP(1);

    // ATTN: no length check, assumes that lengths are equal

    int32_t bit_count = 0;
    for(int i = 0; i < VARSIZE_ANY_EXHDR(arg0); i++) {
        char byte = arg0->vl_dat[i] ^ arg1->vl_dat[i];
        bit_count += count_nonzero_bits(byte);
    }

    PG_RETURN_INT32(bit_count);
}


char count_nonzero_bits(char byte) 
{
    char count = 0;
    while( byte ) {
        count += byte % 2;
        byte >>= 1;
    }

    return count;
}