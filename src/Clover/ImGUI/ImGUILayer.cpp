//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-24
//  Description: Class implementation for ImGUI layer
//===========================================================================

#include "ImGUILayer.hpp"

#include "Application.hpp"
#include "Log.hpp"

#include "imgui.h"
#include "imgui_impl_opengl3.h"

namespace clover {

/*--------------------------------------------------------------------------*/

ImGUILayer::ImGUILayer()
  : Layer("ImGUILayer")
{
}

/*--------------------------------------------------------------------------*/

void ImGUILayer::onAttach()
{
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  auto& io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
  io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

  io.ConfigFlags |=
    ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
    ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  ImGui_ImplOpenGL3_Init("#version 410");

  CLV_CORE_LOG_INFO("ImGUI initialized");
}

/*--------------------------------------------------------------------------*/

void ImGUILayer::onDetach() {}

/*--------------------------------------------------------------------------*/

void ImGUILayer::onUpdate()
{
  auto& io = ImGui::GetIO();
  auto& app = Application::get();
  io.DisplaySize = ImVec2(app.window().width(), app.window().height());

  static bool show_demo_window = true;

  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  // ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  if ( show_demo_window ) ImGui::ShowDemoWindow(&show_demo_window);

  ImGui::Render();

  // glViewport(0, 0, app.window().width(), app.window().height());

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

/*--------------------------------------------------------------------------*/

void ImGUILayer::onEvent(Event& event) {}

}  // namespace clover

