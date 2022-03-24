#include "interface.h"

namespace {
    void draw_nav_bar() {
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Fun")) {
                ImGui::MenuItem("Import");
                ImGui::MenuItem("Export");

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Options")) {
                ImGui::MenuItem("UI");

                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
    }
}

void bezier::draw_interface() {
    draw_nav_bar();
}