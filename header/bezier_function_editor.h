#include "../FunEngine2D/core/include/globals.h"
#include "../FunEngine2D/core/include/vec2.h"
#include "../FunEngine2D/core/include/ecs/ecs.h"
#include "../FunEngine2D/core/include/render/window_manager.h"
#include "../FunEngine2D/core/include/interact/interactable.h"

#include "bezier_function.h"

namespace bezier {
    class bezier_function_editor_t {
    public:
        
        bezier_function_editor_t(fun::vec2f_t, fun::vec2f_t, fun::vec2f_t);
        ~bezier_function_editor_t();

        void resize_bezier_function(fun::vec2f_t);

        void move_editor_window(fun::vec2f_t);
        void resize_editor_window(fun::vec2f_t);

        fun::vec2f_t world_to_bezier(fun::vec2f_t);
        fun::vec2f_t bezier_to_world(fun::vec2f_t);

        void update();

        void draw(fun::winmgr::window_t*, fun::layer_t);

    private:

        void init_anchor(fun::ecs::entity_t);
        void init_controller(fun::ecs::entity_t);
        // void add_anchor();

    private:

        bezier_function_t m_bezier_function;

        fun::vec2f_t m_bezier_function_size;

        fun::vec2f_t m_editor_window_position;
        fun::vec2f_t m_editor_window_size;
    };
}