//
// Created by Piotrek on 29.10.2024.
//
#ifndef RENDERER_H
#define RENDERER_H

class Grid;

namespace Utilities {

    class Renderer {
        Grid* grid;
    public:
        Renderer(Grid* grid);
        void renderTestCircle();
        void renderGrid();
    };
};




#endif //RENDERER_H
