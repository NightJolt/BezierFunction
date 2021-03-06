uniform sampler2D texture;

uniform float width;
uniform float height;
uniform float pixelate;

void main()
{
    vec2 coord = gl_TexCoord[0].xy;
    vec2 dimen = vec2(width, height) * pixelate;

    coord *= dimen;
    coord = vec2(floor(coord.x + .5), floor(coord.y + .5));

    coord /= dimen;

    gl_FragColor = texture2D(texture, coord);
}