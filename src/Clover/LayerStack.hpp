#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for layer stack
//===========================================================================

#include "Layer.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

/** Layers are owned by the layer stack
 */
class CLV_API LayerStack
{
public:
  LayerStack();
  ~LayerStack();

  void push(Layer* layer);
  void pushOverlay(Layer* overlay);
  void pop(Layer* layer);
  void popOverlay(Layer* overlay);

  std::vector<Layer*>::iterator begin() { return layers_.begin(); }

  std::vector<Layer*>::iterator end() { return layers_.end(); }

private:
  std::vector<Layer*> layers_;
  std::vector<Layer*>::iterator layerInsert_;
};

}  // namespace clover
