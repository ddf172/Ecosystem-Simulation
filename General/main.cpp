//
// Created by ddf on 28.10.2024.
//

#include <Utilities/Renderer.h>
#include <Utilities/Tests.cpp>

int main() {
    Utilities::Renderer renderer = Utilities::Renderer();
    renderer.RenderTestCircle();
    Utilities::TestGenerateRandomMapAndPrint(10, 10);
    return 0;
}
