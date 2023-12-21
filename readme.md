# This is the readme for the scop project

## Requirements
- Create a small program that will show a 3D object conceived with a modelization
program like Blender.
- 3D object is stored in a .obj file
- In a window, your 3D object will be displayed in perspective, rotate on itself around its main symmetrical axis.
- By using various colors, it must be possible to distinguish the various
sides.
- The object can be moved on three axis, in both directions.
- A texture must be applicable simply on the object when we press a dedicated
key, and the same key allows us to go back to the different colors. A soft transition
between the two is requested.

## Constraints

- You’re free to use any langages (C / C++ / Rust preferred )
- You’re free to choose between OpenGL, Vulkan, Metal and the MinilibX
- Have a classic Makefile (everything you usually put in there).
- You can use external libraries (other than OpenGL, Vulkan or Metal) ONLY to
manage the windows and the events.
- No libraries are allowed to load the 3D object, nor to make your matrixes or to load
the shaders.

## Graphics Library and Programming language Chosen:

Vulkan, C++
