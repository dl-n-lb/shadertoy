#include "shadertoy_app.hxx"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

ShadertoyApp::ShadertoyApp(i32 width, i32 height, const char* title) {
  if (!glfwInit()) {
    fprintf(stderr, "GLFW Failed to initialize\n");
    exit(EXIT_FAILURE);
  }
    
  glfwSetErrorCallback(error_callback);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    
  _win = glfwCreateWindow(width, height, title, NULL, NULL);
  
  if (!_win) {
    fprintf(stderr, "Failed to create GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwMakeContextCurrent(_win);
  gladLoadGL(glfwGetProcAddress);
  
  glfwSetKeyCallback(_win, key_callback);
}

ShadertoyApp::~ShadertoyApp() {
  glfwDestroyWindow(_win);
  glfwTerminate();
}

void ShadertoyApp::error_callback(i32 err, const char* desc) {
  fprintf(stderr, "Error: %s\n", desc);  
}

void ShadertoyApp::key_callback(GLFWwindow* win, i32 key, i32 scancode, 
                  i32 action, i32 mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(win, GLFW_TRUE);
  }
}

void ShadertoyApp::run() {
  while(!glfwWindowShouldClose(_win)) {
    glfwPollEvents();
    glfwSwapBuffers(_win);
  }
}
