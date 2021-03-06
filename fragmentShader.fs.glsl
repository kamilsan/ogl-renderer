#version 330 core

in vec2 texCoord;

uniform sampler2D diffuse;

out vec4 FragColor;

void main()
{
    FragColor = texture(diffuse, texCoord);
}