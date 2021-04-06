#include "ldac.h"

/***************************************************************************************************
    Unpack Frame Header
***************************************************************************************************/
DECLFUNC LDAC_RESULT unpack_frame_header_ldac(
int *smplrate_id,
int *chconfig_id,
int *frame_length,
int *frame_status,
STREAM *p_stream)
{
    int sync_word;
    int dummy = 0;

    unpack_msb_ldac(8, p_stream, &dummy, &sync_word);

    if (sync_word != 0xaa) {
        return LDAC_S_FALSE;
    }

    unpack_msb_ldac(3, p_stream, &dummy, smplrate_id);
    unpack_msb_ldac(2, p_stream, &dummy, chconfig_id);
    unpack_msb_ldac(9, p_stream, &dummy, frame_length);
    *frame_length = *frame_length + 1;
    unpack_msb_ldac(2, p_stream, &dummy, frame_status);

    return LDAC_S_OK;
}
