#version 140
// the fragment shader operates on each pixel in a given polygon

in vec2 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;


// this is a 3 component float vector that gets outputted to the screen
// for each pixel
out vec4 color;

// let color change over time
uniform float time;
// texture
uniform sampler2D mySampler;


void main(){

   vec4 textureColor = texture(mySampler, fragmentUV);

   // set color r,g,b depending on time and position

   color = textureColor * fragmentColor;

   //color =  vec4(fragmentColor.r * (cos(fragmentPosition.x*4.0 + time)+ 1.0)*0.5,
   //              fragmentColor.g * (cos(fragmentPosition.y*8.0 + time)+ 1.0)*0.5,
   //              fragmentColor.b * (cos(fragmentPosition.x*2.0 + time)+ 1.0)*0.5,
   //              fragmentColor.a);
}
