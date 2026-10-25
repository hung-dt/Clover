#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-24
//  Description: Class definition for ImGUI layer
//===========================================================================

#include "Layer.hpp"

namespace clover {

class MouseButtonPressedEvent;

class MouseButtonReleasedEvent;

class MouseMovedEvent;

class MouseScrolledEvent;

class KeyPressedEvent;

class KeyTypedEvent;

class KeyReleasedEvent;

class WindowResizeEvent;

/*--------------------------------------------------------------------------*/

class CLV_API ImGUILayer : public Layer
{
public:
  ImGUILayer();

  void onAttach() override;

  void onDetach() override;

  void onUpdate() override;

  void onEvent(Event& event) override;

private:
  bool onMouseButtonPressed(MouseButtonPressedEvent& e);

  bool onMouseButtonReleased(MouseButtonReleasedEvent& e);

  bool onMouseMoved(MouseMovedEvent& e);

  bool onMouseScrolled(MouseScrolledEvent& e);

  bool onKeyPressed(KeyPressedEvent& e);

  bool onKeyReleased(KeyReleasedEvent& e);

  bool onKeyTyped(KeyTypedEvent& e);

  bool onWindowResized(WindowResizeEvent& e);

private:
  float time_{};
};

}  // namespace clover
