#include "aroma_minui.h"
#include <stdlib.h>
#include <stdint.h>
#include <minui/minui.h>

extern "C" {

static GRSurface* aroma_surface;
void aroma_minui_init(void) {
	gr_init();
	aroma_surface->width = gr_fb_width();
	aroma_surface->height = gr_fb_height();
	aroma_surface->row_bytes = aroma_surface->width * 4;
	aroma_surface->pixel_bytes = 4;
	aroma_surface->data = (unsigned char*) malloc(sizeof(uint32_t) * aroma_surface->width * aroma_surface->height);
}

int aroma_minui_get_fb_width(void) {
	return aroma_surface->width;
}

int aroma_minui_get_fb_height(void) {
	return aroma_surface->height;
}

void* aroma_minui_get_data(void) {
	return aroma_surface->data;
}

void aroma_minui_flip(void) {
	gr_blit(aroma_surface, 0, 0, aroma_surface->width, aroma_surface->height, 0, 0);
	gr_flip();
}

}
