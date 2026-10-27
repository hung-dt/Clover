# Development Notes

## What is a Game Engine?

- A platform which you can use to build games or interactive graphics apps.
  - transforms data from one format into another format
  - provides ways to interact with that data

### Subsystems

- Platform abstraction layer to support multiple platforms
- Level editors
...

## The Design

- Entry point: what happens when we launch the engine?
- Application layer: life cycle and events
- Windowing layer:
  - handles input and events
- Rendering layer: biggest system
- Render API abstraction
- Debugging support:
  - logging system
  - profile
- Scripting language built-in
- Memory management
- ECS (Entity Component System)
- Physics
- File I/O, VFS

## Project Setup

## Event System

- Application creates Windows, so the Application will set up a kind of messaging system
- The window should not have idea about Application
- When event occurs inside the actual window:
  - the window class will receive an event callback
  - the window will construct an event and then somehow propagate back to the application
  - the application will dispatch the event to be handled with appropriate handler.

## Window Abstraction and GLFW

- Window class per platform

## Layers

- Layer can be rendered (can be shown or hidden) on screen in order and can receive events.
  - Game layer
  - In-game UI layer
  - Debug layer (ImGUI)

- Events handling???

## Modern OpenGL

- GL Loader with glad
