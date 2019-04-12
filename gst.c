#include <stdio.h>
#include "functions.h"




static GstStaticCaps caps_1 = {3.14, "_S1_AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA_1E_"};
static GstStaticCaps caps_2 = {5.55, "_S2_BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB_2E_"};

int main()
{
    dump_caps("caps_1",&caps_1);
    dump_caps("caps_2",&caps_2);

    check_struct(&caps_1, &caps_2);
    
    dump_caps("caps_1",&caps_1);
    dump_caps("caps_2",&caps_2);
    return 0;
}
