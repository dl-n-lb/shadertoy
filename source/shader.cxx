#include "shader.hxx"

ShaderProgram::ShaderProgram() {
  glCreateProgramPipelines(1, &_program_id);
}

ShaderProgram& ShaderProgram::AddShader(ShaderStageInfo_t stage, str filepath) {
  str src = open_file(filepath); // to avoid lifetime issues i think
  const char* src_c = src.c_str();
  GLuint id = glCreateShaderProgramv(stage.stage, 1, &src_c);
  glUseProgramStages(_program_id, stage.stage_bits, id);
  _shaders[stage] = id;
  return *this;
}

str ShaderProgram::open_file(str filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    fprintf(stderr, "Failed to open shader source file: %s", filepath.c_str());
    // TODO: EXIT MORE ELEGANTLY (EXCEPTION OR SMTH)
    exit(EXIT_FAILURE);
  }
  
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

void ShaderProgram::Bind() const {
  glBindProgramPipeline(_program_id);
}

bool ShaderStageInfo_t::operator==(const ShaderStageInfo_t& other) const {
  return (stage == other.stage) && (stage_bits == other.stage_bits);
}

size_t std::hash<ShaderStageInfo_t>::operator()(const ShaderStageInfo_t& info) const {
  return hash<int>()(info.stage);
}
