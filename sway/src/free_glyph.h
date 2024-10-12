#ifndef FREE_GLYPH_H_
#define FREE_GLYPH_H_

#include <stdlib.h>
#include "./la.h"

#define GLEW_STATIC
#include <GL/glew.h>

#define GL_GLEXT_PROTOTYPES
#include "{your_own_path}/SDL_opengl.h"


#include <ft2build.h>
#include FT_FREETYPE_H

#include "simple_renderer.h"

#define FREE_GLYPH_FONT_SIZE 64

typedef struct {
    float ax;
    float ay;

    float bw;
    float bh;

    float bl;
    float bt;

    float tx;
} Glyph_Metric;

#define GLYPH_METRICS_CAPACITY 128

typedef struct {
    FT_UInt atlas_width;
    FT_UInt atlas_height;
    GLuint glyphs_texture;
    Glyph_Metric metrics[GLYPH_METRICS_CAPACITY];
} Free_Glyph_Atlas;

void free_glyph_atlas_init(Free_Glyph_Atlas *atlas, FT_Face face);
float free_glyph_atlas_cursor_pos(const Free_Glyph_Atlas *atlas, const char *text, size_t text_size, Vec2f pos, size_t col);
void free_glyph_atlas_measure_line_sized(Free_Glyph_Atlas *atlas, const char *text, size_t text_size, Vec2f *pos);
void free_glyph_atlas_render_line_sized(Free_Glyph_Atlas *atlas, Simple_Renderer *sr, const char *text, size_t text_size, Vec2f *pos, Vec4f color);

#endif
