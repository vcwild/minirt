# Ray Tracer *.rt file settings

## Base settings

### Ambient light

A 0.2 255,255,255

- identifier: A
- ambient lighting ratio in range [0.0,1.0]: 0.2
- R,G,B colors in range [0-255]: 255, 255, 255

### Camera

C -50.0,0,20 0,0,1 70

- identifier: C
- x,y,z coordinates of the view point: 0.0,0.0,20.6
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
- FOV : Horizontal field of view in degrees in range [0,180]

### Light

L -40.0,50.0,0.0 0.6 10,0,255

- identifier: L
- x,y,z coordinates of the light point: 0.0,0.0,20.6
- the light brightness ratio in range [0.0,1.0]: 0.6
- (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

## Shapes

### Sphere

sp 0.0,0.0,20.6 12.6 10,0,255

- identifier: sp
- x,y,z coordinates of the sphere center: 0.0,0.0,20.6
- the sphere diameter: 12.6
- R,G,B colors in range [0-255]: 10, 0, 255

### Plane

pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225

- identifier: pl
- x,y,z coordinates: 0.0,0.0,-10.0
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
- R,G,B colors in range [0-255]: 0, 0, 255

### Cylinder

cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255

- identifier: cy
- x,y,z coordinates: 50.0,0.0,20.6
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
- the cylinder diameter: 14.2
- the cylinder height: 21.42
- R,G,B colors in range [0,255]: 10, 0, 255
