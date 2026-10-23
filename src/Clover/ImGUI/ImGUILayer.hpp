#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-24
//  Description: Class definition for ImGUI layer
//===========================================================================

#include "Layer.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API ImGUILayer : public Layer
{
public:
  ImGUILayer();

  void onAttach() override;

  void onDetach() override;

  void onUpdate() override;

  void onEvent(Event& event) override;
};

}  // namespace clover
