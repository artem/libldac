#include "ldac.h"

/***************************************************************************************************
    Free Memory
***************************************************************************************************/
DECLFUNC void free_decode_ldac(
SFINFO *p_sfinfo)
{
    int ich;
    int nchs = p_sfinfo->cfg.ch;

    /* Free AB */
    if (p_sfinfo->p_ab != (AB *)NULL) {
        free(p_sfinfo->p_ab);
        p_sfinfo->p_ab = (AB *)NULL;
    }

    /* Free AC */
    for (ich = 0; ich < nchs; ich++) {
        if (p_sfinfo->ap_ac[ich] != (AC *)NULL) {
            if (p_sfinfo->ap_ac[ich]->p_acsub != (ACSUB *)NULL) {
                free(p_sfinfo->ap_ac[ich]->p_acsub);
                p_sfinfo->ap_ac[ich]->p_acsub = (ACSUB *)NULL;
            }
            free(p_sfinfo->ap_ac[ich]);
            p_sfinfo->ap_ac[ich] = (AC *)NULL;
        }
    }

    return;
}
