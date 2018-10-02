#include "aroma_minui.h"
#include <stdbool.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <minui/minui.h>
//#include "../aroma.h"
extern "C" {
static GRSurface *aroma_surface;
void aroma_minui_init(void) {
	printf("GR_Init\n");
	printf("Initializing graphics.\n");
	if (gr_init() != 0) {
	    printf("Error initializing graphics.\n");
	}	
	aroma_surface = (GRSurface*) malloc (sizeof(GRSurface));	
	printf("GR_Width=%d\n",gr_fb_width());
	aroma_surface->width = gr_fb_width();
	printf("GR_Height=%d\n",gr_fb_height());
	aroma_surface->height = gr_fb_height();
	printf("GR_Row\n");
	aroma_surface->row_bytes = aroma_surface->width * 4;
	printf("GR_Bytes\n");
	aroma_surface->pixel_bytes = 4;
	printf("GR_data\n");        
        aroma_surface->data = (unsigned char*) malloc(aroma_surface->height * aroma_surface->row_bytes);
        if (!aroma_surface->data) {
            printf("failed to allocate in-memory surface");
        }
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
