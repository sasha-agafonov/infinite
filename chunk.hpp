#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include <glm/ext.hpp>
#include "dynamic_indices.hpp"


class terrain;

class dynamic_indices;

class chunk {

    public:

        chunk(int vertices_per_side, int chunk_start_x, int chunk_start_y, 
              terrain* polite_terrain, dynamic_indices* lod_object);

        int lod;
        int curr_lod;
        int prev_lod;

        void print_info();
        void update_vertices(int chunk_start_x, int chunk_start_y);
        void build_vertices(int chunk_start_x, int chunk_start_y);
        void build_indices();
        void set_buffers();

        void draw();
        void update_distance(glm :: vec2 observer_pos);


    private:

        int vertices_per_side;

        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;

        float distance;

        terrain *polite_terrain;
        dynamic_indices *lod_object;

        glm :: vec2 chunk_start;
        glm :: vec2 global_pos;

        std :: vector <float> vertices;
        std :: vector <unsigned int> indices;

        void set_lod();

};

#endif
