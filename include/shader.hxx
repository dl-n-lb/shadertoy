#ifndef SHADERTOY_SHADER_HXX
#define SHADERTOY_SHADER_HXX

#include <types/type_alias.hxx>
#include <glad/gl.h>
#include <fstream>

struct ShaderStageInfo_t {
  GLuint stage;
  GLbitfield stage_bits;
  
  bool operator==(const ShaderStageInfo_t& other) const;
};

namespace std {
  template<> 
  struct hash<ShaderStageInfo_t> {
    size_t operator()(const ShaderStageInfo_t& info) const;
  };
}

static constexpr ShaderStageInfo_t VERTEX_STAGE = {
  GL_VERTEX_SHADER,
  GL_VERTEX_SHADER_BIT
};

static constexpr ShaderStageInfo_t FRAGMENT_STAGE = {
  GL_FRAGMENT_SHADER,
  GL_FRAGMENT_SHADER_BIT
};


class ShaderProgram {
public: 
  ShaderProgram();  
  ShaderProgram& AddShader(ShaderStageInfo_t stage, str filepath);
  
  void Bind() const;
private:
  str open_file(str filepath);
  
  GLuint _program_id;
  hashmap<ShaderStageInfo_t, GLuint> _shaders;
};

#endif // SHADERTOY_SHADER_HXX