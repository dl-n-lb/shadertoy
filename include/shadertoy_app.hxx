#ifndef SHADERTOY_APP_HXX
#define SHADERTOY_APP_HXX

#include <glad/gl.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "types/type_alias.hxx"

#include <stdio.h>

class ShadertoyApp {
public:
  ShadertoyApp(i32 width, i32 height, const char* title);
  
  void run();
  
  ~ShadertoyApp();
  
private:
  static void error_callback(i32 err, const char* desc);
  
  static void key_callback(GLFWwindow*, i32, i32, i32, i32);  
  GLFWwindow* _win;
};

#endif //SHADERTOY_APP_HXX