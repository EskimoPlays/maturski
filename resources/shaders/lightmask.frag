uniform vec2 lightCenter;
uniform float lightRadius;

void main() {
    vec2 fragCoord = gl_FragCoord.xy;

    float distanceFromLight = distance(fragCoord, lightCenter);

    float intensity = 1.0 - smoothstep(lightRadius * 0.5, lightRadius, distanceFromLight);
    intensity = clamp(intensity, 0.0, 1.0);

    float finalDarkness = 1.0 - intensity;

    gl_FragColor = vec4(vec3(0.0), finalDarkness);
}