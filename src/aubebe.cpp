#include "aubebe.h"

#include "imgui.h"

void AuBeBe::ShowMainWindow(bool* p_open)
{
    ImGui::Begin("AuBeBe", p_open);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("Hello from aubebe!");
    if (ImGui::Button("Close Me"))
        *p_open = false;
    ImGui::End();
}
