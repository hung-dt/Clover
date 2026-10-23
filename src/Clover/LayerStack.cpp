//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class implementation for layer stack
//===========================================================================

#include "LayerStack.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

LayerStack::LayerStack()
{
  layerInsert_ = layers_.begin();
}

/*--------------------------------------------------------------------------*/

/** Layers are owned by the layer stack, so we need to deallocate all layers
 * when the stack is destroyed.
 */
LayerStack::~LayerStack()
{
  for ( auto& l : layers_ ) {
    delete l;
  }
}

/*--------------------------------------------------------------------------*/

void LayerStack::push(Layer* layer)
{
  layerInsert_ = layers_.emplace(layerInsert_, layer);
}

/*--------------------------------------------------------------------------*/

/** Overlay layer is always pushed after all other layers
 */
void LayerStack::pushOverlay(Layer* overlay)
{
  layers_.emplace_back(overlay);
}

/*--------------------------------------------------------------------------*/

/** Remove a layer from the stack
 */
void LayerStack::pop(Layer* layer)
{
  if (
    auto it = std::find(layers_.begin(), layers_.end(), layer);
    it != layers_.end() ) {
    layers_.erase(it);
    layerInsert_--;
  }
}

/*--------------------------------------------------------------------------*/

void LayerStack::popOverlay(Layer* overlay)
{
  if (
    auto it = std::find(layers_.begin(), layers_.end(), overlay);
    it != layers_.end() ) {
    layers_.erase(it);
  }
}
};  // namespace clover
