#include "accdet_custom_def.h"
#include <accdet_custom.h>

//key press customization: long press time
struct headset_key_custom headset_key_custom_setting = {
	2000
};

struct headset_key_custom* get_headset_key_custom_setting(void)
{
	return &headset_key_custom_setting;
}

#ifdef  ACCDET_MULTI_KEY_FEATURE
static struct headset_mode_settings cust_headset_settings = {
	0x900, 0x200, 1, 0x1f0, 0x800, 0x800, 0x20
};
#else
//headset mode register settings(for MT6575)
static struct headset_mode_settings cust_headset_settings = {
	0x1900, 0x140, 1, 0x12c, 0x3000, 0x3000, 0x400
};
#endif

struct headset_mode_settings{
    int pwm_width;	//pwm frequence
    int pwm_thresh;	//pwm duty 
    int fall_delay;	//falling stable time
    int rise_delay;	//rising stable time
    int debounce0;	//hook switch or double check debounce
    int debounce1;	//mic bias debounce
    int debounce3;	//plug out debounce
};