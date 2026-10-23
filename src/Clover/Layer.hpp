#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for Layers
//===========================================================================

#include "Core.hpp"

namespace clover {

class Event;

/*--------------------------------------------------------------------------*/

class CLV_API Layer
{
public:
  Layer(const std::string& name = "Layer")
    : name_(name)
  {
  }

  virtual ~Layer() = default;

  virtual void onAttach() {}

  virtual void onDetach() {}

  virtual void onUpdate() {}

  virtual void onEvent(Event& event) {}

  inline const std::string& name() const { return name_; }

  inline bool isEnabled() const { return isEnabled_; }

protected:
  std::string name_;
  bool isEnabled_{ false };
};

}  // namespace clover
