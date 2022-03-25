#include "../FunEngine2D/core/include/globals.h"
#include "../FunEngine2D/core/include/vec2.h"
#include "../FunEngine2D/core/include/ecs/ecs.h"

namespace bezier {
    struct anchor_data_t {
        anchor_data_t(fun::vec2f_t, fun::ecs::entity_t, fun::ecs::entity_t);

        fun::vec2f_t position;
        fun::ecs::entity_t left_controller;
        fun::ecs::entity_t right_controller;
    };
    
    struct controller_data_t {
        controller_data_t(fun::vec2f_t, fun::ecs::entity_t, fun::ecs::entity_t, bool);

        fun::vec2f_t position;
        fun::ecs::entity_t anchor;
        fun::ecs::entity_t other_controller;
        bool is_left;
    };
}

namespace bezier {
    class bezier_function_t {
    public:
        
        bezier_function_t();
        ~bezier_function_t();

        void add_anchor(fun::vec2f_t, bool = true, bool = true);

        std::vector <fun::ecs::entity_t>& get_anchors();

    private:

        std::vector <fun::ecs::entity_t> m_anchors;
    };
}