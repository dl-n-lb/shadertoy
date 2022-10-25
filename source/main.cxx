#include <string>

#include "types/type_alias.hxx"
#include "shadertoy_app.hxx"
#include "shader.hxx"

const static i32 win_width = 800;
const static i32 win_height = 600;

i32 main(i32, char**) {
  ShadertoyApp app{win_width, win_height, "Shadertoy App"};
  
  ShaderProgram program{};
  program.AddShader(VERTEX_STAGE, "")
         .AddShader(FRAGMENT_STAGE, "");
  app.run();
  
  return EXIT_SUCCESS;
}