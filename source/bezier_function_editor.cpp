#include "bezier_function_editor.h"

namespace {
    const sf::Color CONTROLLER_COLOR = { 255, 255, 255 };
    const sf::Color ANCHOR_COLOR = { 255, 0, 0 };

    constexpr float CONTROLLER_RADIUS = 4.f;
    constexpr float ANCHOR_RADIUS = 6.f;
}

bezier::bezier_function_editor_t::bezier_function_editor_t(fun::vec2f_t bezier_function_size, fun::vec2f_t editor_window_position, fun::vec2f_t editor_window_size) {
    resize_bezier_function(bezier_function_size);

    move_editor_window(editor_window_position);
    resize_editor_window(editor_window_size);

    for (auto anchor_entity : m_bezier_function.get_anchors()) {
        init_anchor(anchor_entity);
    }
}

bezier::bezier_function_editor_t::~bezier_function_editor_t() {
}

void bezier::bezier_function_editor_t::resize_bezier_function(fun::vec2f_t new_bezier_function_size) {
    m_bezier_function_size = new_bezier_function_size;
}

void bezier::bezier_function_editor_t::move_editor_window(fun::vec2f_t new_editor_window_position) {
    m_editor_window_position = new_editor_window_position;
}

void bezier::bezier_function_editor_t::resize_editor_window(fun::vec2f_t new_editor_window_size) {
    m_editor_window_size = new_editor_window_size;
}

void bezier::bezier_function_editor_t::draw(fun::winmgr::window_t* window, fun::layer_t layer) {
    const fun::layer_t points_layer = layer + 1;

    for (auto anchor_entity : m_bezier_function.get_anchors()) {
        auto& anchor_data = fun::ecs::get_component <anchor_data_t> (anchor_entity);

        // ? anchor
        {
            auto& circle = fun::ecs::get_component <sf::CircleShape> (anchor_entity);

            circle.setPosition(bezier_to_world(anchor_data.position).to_sf());

            window->draw_world(circle, points_layer);
        }
    }
}

void bezier::bezier_function_editor_t::init_anchor(fun::ecs::entity_t anchor_entity) {
    auto& anchor_data = fun::ecs::get_component <anchor_data_t> (anchor_entity);

    init_controller(anchor_data.left_controller);
    init_controller(anchor_data.right_controller);

    auto& circle = fun::ecs::add_component <sf::CircleShape> (anchor_entity, ANCHOR_RADIUS, 16);

    circle.setFillColor(ANCHOR_COLOR);
    circle.setOutlineThickness(0);
    circle.setOrigin(ANCHOR_RADIUS, ANCHOR_RADIUS);
}

void bezier::bezier_function_editor_t::init_controller(fun::ecs::entity_t controller_entity) {
    if (controller_entity == fun::ecs::nullentity) return;

    auto& circle = fun::ecs::add_component <sf::CircleShape> (controller_entity, CONTROLLER_RADIUS, 16);

    circle.setFillColor(CONTROLLER_COLOR);
    circle.setOutlineThickness(0);
    circle.setOrigin(CONTROLLER_RADIUS, CONTROLLER_RADIUS);
}

fun::vec2f_t bezier::bezier_function_editor_t::world_to_bezier(fun::vec2f_t p) {
    return fun::vec2f_t { 1.f, 1.f } - (p - m_editor_window_position) / m_editor_window_size;
}

fun::vec2f_t bezier::bezier_function_editor_t::bezier_to_world(fun::vec2f_t p) {
    return (fun::vec2f_t { 1.f, 1.f } - p) * m_editor_window_size + m_editor_window_position;
}