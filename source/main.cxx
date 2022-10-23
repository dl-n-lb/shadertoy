#include <stdio.h>
#include <string>

#include "types/type_alias.hxx"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

const static i32 win_width = 800;
const static i32 win_height = 600;

void error_callback(i32 error, const char* desc) {
  fprintf(stderr, "Error: %s\n", desc);
}

static void key_callback(GLFWwindow* win, i32 key, i32 scancode, 
                         i32 action, i32 mods) {
  if (key == GLFW_KEY_ESCAPE && action) {
    glfwSetWindowShouldClose(win, GLFW_TRUE);
  }
}

i32 main(i32, char**) {
  if (!glfwInit()) {
    fprintf(stderr, "GLFW Failed to Initialize!\n");
    return EXIT_FAILURE;
  }
  
  glfwSetErrorCallback(error_callback);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  
  GLFWwindow* win = glfwCreateWindow(win_width, win_height, "Shadertoy",
                                     NULL, NULL);
  if (!win) {
    fprintf(stderr, "GLFW Window failed to be created \
      (Window or GL Context creation failed)!\n");
    glfwTerminate();
    return EXIT_FAILURE;
  }
  
  glfwMakeContextCurrent(win);
  gladLoadGL(glfwGetProcAddress);
  
  glfwSetKeyCallback(win, key_callback);

  while (!glfwWindowShouldClose(win)) {
    glfwSwapBuffers(win);
  }
  
  glfwDestroyWindow(win);
  glfwTerminate();
  return EXIT_SUCCESS;
}