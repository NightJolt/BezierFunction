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
#include "bezier_function_editor.h"

int main () {
    fun::winmgr::init(fun::winmgr::window_data_t("Bezier Function Editor"));
    auto* window = fun::winmgr::main_window;

    bezier::bezier_function_editor_t bezier_function_editor({ 100, 100 }, { 10, 10 }, { 300, 100 });
    
    while (window->render.isOpen()) {
        fun::time::recalculate();
        fun::input::listen();
        fun::interaction::update();
        fun::winmgr::update();

        bezier::draw_interface();

        bezier_function_editor.draw(window, 0);

        window->display(sf::Color::Black);
    }

    fun::winmgr::close();

    return 0;
};