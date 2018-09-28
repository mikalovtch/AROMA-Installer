#ifndef AROMA_MINUI_H
#define AROMA_MINUI_H

#ifdef __cplusplus
extern "C" {
#endif

void aroma_minui_init(void);
int aroma_minui_get_fb_width(void);
int aroma_minui_get_fb_height(void);
void* aroma_minui_get_data(void);
void aroma_minui_flip(void);

#ifdef __cplusplus
}
#endif

#endif // AROMA_MINUI_H
