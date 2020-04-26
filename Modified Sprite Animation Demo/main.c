/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2013, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <jo/jo.h>

static int ring_anim_id = 0;
static int ring_position_x = 0;
static int ring_position_y = 0;

void			my_draw(void)
{
	jo_printf(0, 0, "Use the dpad to move the ring around the screen");

	/* The last step is to display the current sprite of the animation using the animation id. */
	jo_sprite_draw3D(ring_anim_id, ring_position_x, ring_position_y, 490);
}

void			my_gamepad(void)
{
	if (!jo_is_pad1_available())
		return;
	if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
		ring_position_x -= 2;
	if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
		ring_position_x += 2;
	if (jo_is_pad1_key_pressed(JO_KEY_UP))
		ring_position_y -= 2;
	if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
		ring_position_y += 2;
}

void			jo_main(void)
{
	jo_core_init(JO_COLOR_Black);
	ring_anim_id = jo_sprite_add_tga(JO_ROOT_DIR, "1.TGA", JO_COLOR_Green);
	jo_core_add_callback(my_gamepad);
	jo_core_add_callback(my_draw);
	jo_core_run();
}

/*
** END OF FILE
*/
