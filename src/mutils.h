/*
   Copyright (C) 2010,2011 bg <bg_one@mail.ru>
*/
#ifndef CHAN_QUECTEL_MUTILS_H_INCLUDED
#define CHAN_QUECTEL_MUTILS_H_INCLUDED

#include <string.h>

#include "ast_config.h"

#include <asterisk/strings.h>
#include <asterisk/utils.h>

#define STRLEN(string) (sizeof(string) - 1u)

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

static inline const char* enum2str_def(const unsigned value, const char* const names[], const unsigned items, const char* const def)
{
    // bounds first: S_COR() evaluates its second argument before the condition, so
    // names[value] was read even out of range (gsm_reg_status = -1 before any +CREG,
    // e.g. no SIM: "quectel show device state" crashed Asterisk)
    if (value >= items || ast_strlen_zero(names[value])) {
        return def;
    }
    return names[value];
}

static inline const char* enum2str(const unsigned value, const char* const names[], const unsigned items)
{
    return enum2str_def(value, names, items, "unknown");
}

static inline int str2enum(const char* const value, const char* const options[], const unsigned items)
{
    for (unsigned i = 0; i < items; ++i) {
        if (!strcasecmp(value, options[i])) {
            return (int)i;
        }
    }

    return -1;
}

#endif /* CHAN_QUECTEL_MUTILS_H_INCLUDED */
