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

const fun::vec2f_t windows_size = { 600, 300 };
const fun::vec2f_t editor_position = { 40, 60 };
const fun::vec2f_t editor_size = windows_size - fun::vec2f_t { 80, 100 };

int main () {
    fun::winmgr::init(fun::winmgr::window_data_t("Bezier Function Editor", windows_size));
    auto* window = fun::winmgr::main_window;

    window->world_view.move((windows_size * .5f).to_sf());

    bezier::bezier_function_editor_t bezier_function_editor({ 100, 100 }, editor_position, editor_size);
    
    while (window->render.isOpen()) {
        fun::time::recalculate();
        fun::input::listen();
        fun::interaction::update();
        fun::winmgr::update();



        bezier::draw_interface();

        bezier_function_editor.draw(window, 0);

        fun::debugger::display();

        window->display(sf::Color::Black);
    }

    fun::winmgr::close();

    return 0;
};