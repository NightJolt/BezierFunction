#include "FunEngine2D/core/include/globals.h"
#include "FunEngine2D/core/include/vec2.h"
#include "FunEngine2D/core/include/transform.h"
#include "FunEngine2D/core/include/render/window_manager.h"
#include "FunEngine2D/core/include/resources.h"
#include "FunEngine2D/core/include/_time.h"
#include "FunEngine2D/core/include/input.h"
#include "FunEngine2D/core/include/tools/debugger.h"
#include "FunEngine2D/core/include/ecs/ecs.h"
#include "FunEngine2D/core/include/interact/interaction.h"
#include "FunEngine2D/core/include/interact/interactable.h"

#include "interface.h"

int main () {
    fun::winmgr::init(fun::winmgr::window_data_t("Bezier Function Editor"));
    auto* window = fun::winmgr::main_window;
    
    while (window->render.isOpen()) {
        fun::time::recalculate();
        fun::input::listen();
        fun::interaction::update();
        fun::winmgr::update();

        bezier::draw_interface();

        window->display(sf::Color::Black);
    }

    fun::winmgr::close();

    return 0;
};