/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-18 14:16:47
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include "tips.h"

#define _(string) gettext(string)

int setLocale()
{
    setlocale (LC_ALL, "");
    bindtextdomain ("gettext_test", "language");
    textdomain ("gettext_test");
    printf (_("Hello world!\n"));

    return 0;
}
