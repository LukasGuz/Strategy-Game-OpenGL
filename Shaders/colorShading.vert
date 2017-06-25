#version 140
// the vertex shader operates on each vertex

// input data from VBO. each vertex is 2 floats
in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec4 fragmentColor;
out vec2 fragmentPosition;
out vec2 fragmentUV;

void main(){
   // set the x,y position on the screen
   gl_Position.xy = vertexPosition;
   // the z position = 0 cause in 2D
   gl_Position.z = 0.0;

   // indicate that the coordinates are normalized
   gl_Position.w = 1.0;

   fragmentPosition = vertexPosition;

   fragmentColor = vertexColor;

   fragmentUV = vertexUV;
}
