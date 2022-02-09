#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#include "gex.h"
// breath Meter HUD

// 0x030233E0
ALIGNED8 static const u8 breath_meter_left_side_eight_health[] = {
#include "actors/breath_meter/breath_meter_left_side_eight_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_eight_health[] = {
#include "actors/breath_meter/breath_meter_right_side_eight_health.rgba16.inc.c"
};

// 0x030253E0
ALIGNED8 static const u8 breath_meter_left_side_seven_health[] = {
#include "actors/breath_meter/breath_meter_left_side_seven_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_seven_health[] = {
#include "actors/breath_meter/breath_meter_right_side_seven_health.rgba16.inc.c"
};

// 0x030263E0
ALIGNED8 static const u8 breath_meter_left_side_six_health[] = {
#include "actors/breath_meter/breath_meter_left_side_six_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_six_health[] = {
#include "actors/breath_meter/breath_meter_right_side_six_health.rgba16.inc.c"
};

// 0x030273E0
ALIGNED8 static const u8 breath_meter_left_side_five_health[] = {
#include "actors/breath_meter/breath_meter_left_side_five_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_five_health[] = {
#include "actors/breath_meter/breath_meter_right_side_five_health.rgba16.inc.c"
};

// 0x030283E0
ALIGNED8 static const u8 breath_meter_left_side_four_health[] = {
#include "actors/breath_meter/breath_meter_left_side_four_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_four_health[] = {
#include "actors/breath_meter/breath_meter_right_side_four_health.rgba16.inc.c"
};

ALIGNED8 static const u8 breath_meter_left_side_three_health[] = {
#include "actors/breath_meter/breath_meter_left_side_three_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_three_health[] = {
#include "actors/breath_meter/breath_meter_right_side_three_health.rgba16.inc.c"
};

ALIGNED8 static const u8 breath_meter_left_side_two_health[] = {
#include "actors/breath_meter/breath_meter_left_side_two_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_two_health[] = {
#include "actors/breath_meter/breath_meter_right_side_two_health.rgba16.inc.c"
};

ALIGNED8 static const u8 breath_meter_left_side_one_health[] = {
#include "actors/breath_meter/breath_meter_left_side_one_health.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side_one_health[] = {
#include "actors/breath_meter/breath_meter_right_side_one_health.rgba16.inc.c"
};

ALIGNED8 static const u8 breath_meter_left_side[] = {
#include "actors/breath_meter/breath_meter_left_side.rgba16.inc.c"
};

// 0x030243E0
ALIGNED8 static const u8 breath_meter_right_side[] = {
#include "actors/breath_meter/breath_meter_right_side.rgba16.inc.c"
};

// 0x030293E0
const u8 *const breath_meter_segments_lut[] = {
    breath_meter_left_side_eight_health,
    breath_meter_right_side_eight_health,
    breath_meter_left_side_seven_health,
    breath_meter_right_side_seven_health,
    breath_meter_left_side_six_health,
    breath_meter_right_side_six_health,
    breath_meter_left_side_five_health,
    breath_meter_right_side_five_health,
    breath_meter_left_side_four_health,
    breath_meter_right_side_four_health,
    breath_meter_left_side_three_health,
    breath_meter_right_side_three_health,
    breath_meter_left_side_two_health,
    breath_meter_right_side_two_health,
    breath_meter_left_side_one_health,
    breath_meter_right_side_one_health,
    breath_meter_left_side,
    breath_meter_right_side,
};

// 0x03029400
static Vtx vtx_breathmeter[] = {
	{ -32 , -32 ,  0,  0 ,        0 ,              0,   255,255,255,220}, 
	{   0 , -32 ,  0,  0 , (31 << 5),              0,   255,255,255,220}, 
	{   0 ,  32 ,  0,  0 , (31 << 5),    ( -63 << 5),   255,255,255,220}, 
	{ -32 ,  32 ,  0,  0 ,         0,    ( -63 << 5),   255,255,255,220}, 

	{   0 , -32 ,  0,  0 ,        1 ,              0,   255,255,255,220}, 
	{  32 , -32 ,  0,  0 , (31 << 5),              0,   255,255,255,220}, 
	{  32 ,  32 ,  0,  0 , (31 << 5),    ( -63 << 5),   255,255,255,220}, 
	{   0 ,  32 ,  0,  0 ,        1 ,    ( -63 << 5),   255,255,255,220}, 
};

// 0x03029480 - 0x03029530
const Gfx RCP_breathmeter_on[] = {
	gsDPPipeSync(),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
	gsDPSetRenderMode(G_RM_XLU_SURF,G_RM_XLU_SURF2),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON),
	gsSPVertex(&vtx_breathmeter[0],  8, 0), 
	gsSPEndDisplayList(), 
};


const Gfx RCP_breathmeter_txt[] = {

    gsxDPLoadTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0,
			 		G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 					5,6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPEndDisplayList(), 
};


const Gfx RCP_breathmeter_off[] = {
	gsDPPipeSync(),
	gsSPTexture(0xffff, 0xffff, 0, 0, 0),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_SHADING_SMOOTH|G_LIGHTING),
	gsSPEndDisplayList(), 

};
#pragma GCC diagnostic pop

