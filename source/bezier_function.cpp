#include "bezier_function.h"

bezier::anchor_data_t::anchor_data_t(fun::vec2f_t p, fun::ecs::entity_t l_c, fun::ecs::entity_t r_c) : position(p), left_controller(l_c), right_controller(r_c) {}

bezier::controller_data_t::controller_data_t(fun::vec2f_t p, fun::ecs::entity_t a, fun::ecs::entity_t o_c, bool i_l) : position(p), anchor(a), other_controller(o_c), is_left(i_l) {}

namespace {
    const fun::vec2f_t CONTROLLER_OFFSET = { .05f, .1f };
}

bezier::bezier_function_t::bezier_function_t() {
    add_anchor({ 0.f, .5f }, false, true);
    add_anchor({ .5f, .5f }, true, true);
    add_anchor({ 1.f, .5f }, true, false);
}

void bezier::bezier_function_t::add_anchor(fun::vec2f_t position, bool create_left_controller, bool create_right_controller) {
    auto anchor_entity = fun::ecs::new_entity();
    auto left_controller_entity = create_left_controller ? fun::ecs::new_entity() : fun::ecs::nullentity;
    auto right_controller_entity = create_right_controller ? fun::ecs::new_entity() : fun::ecs::nullentity;

    if (create_left_controller) {
        fun::ecs::add_component <controller_data_t> (left_controller_entity, position - CONTROLLER_OFFSET, anchor_entity, right_controller_entity, true);
    }

    if (create_right_controller) {
        fun::ecs::add_component <controller_data_t> (left_controller_entity, position + CONTROLLER_OFFSET, anchor_entity, left_controller_entity, false);
    }
    
    fun::ecs::add_component <anchor_data_t> (anchor_entity, position, left_controller_entity, right_controller_entity);
}