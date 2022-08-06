<div align="center">
  <img src=".github/assets/minirt.png" width="350px" />
</div>
<div align="center">
  <img src="https://img.shields.io/github/languages/count/vcwild/philosophers?color=%23E96418&style=flat-square" alt="languages" />
  <img src="https://img.shields.io/github/license/vcwild/philosophers?color=%23E96418&style=flat-square" alt="license" />
  <img src="https://img.shields.io/github/repo-size/vcwild/philosophers?color=%23E96418&style=flat-square" alt="repo size" />
</div>

# MiniRT

This project is an implementation of a [Ray Tracer](https://en.wikipedia.org/wiki/Ray_tracing) using the path tracing algorithm.

## Brief

A ray tracer is a program that takes a scene and a camera and renders the scene to a screen. The properties of a ray tracer are:

- The camera has position and a direction
- The camera can be rotated, zoomed in and out, and moved around the scene
- The objects in the scene have a color, shape, material and position
- There is light in the scene
- The light emits rays that intersect with objects in the scene

## Dependencies

Install libs

```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

If you want to run tests on project clone munit into /tests folder
```sh
git submodule init
```

This project uses minilibx-linux
MinilibX, a simple X-Window (X11R6) programming API in C, designed for students, suitable for X-beginners.

Unofficial documentation for minilibx

- [Harm Smiths Docs](https://harm-smits.github.io/42docs/libs/minilibx)

- [Getting started with the minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)

### How the Ray Tracer algorithm works

1. Cast a ray into the scene, and find where it strikes a surface.
2. Cast a ray from that point toward each light source to determine which
   lights illuminate that point.
3. If the surface is reflective, cast a new ray in the direction of reflection and
   recursively determine what color is reflected there.
4. If the surface is transparent, do the same thing in the direction of refrac-
   tion.
5. Combine all colors that contribute to the point (the color of the surface,
   the reflection, and refraction) and return that as the color of the pixel.

## References

- [The Ray Tracer Challenge](https://www.raytracing.org/raytracerchallenge/)
- [How Ray Tracing Works](https://www.youtube.com/watch?v=lKIytgt3KXM)
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
- [Simple Method for Creating 3D Images](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing)
- [Khan Academy Rendering](https://www.khanacademy.org/computing/pixar/rendering)
- [Notion 1 Resource](https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436)
- [Disney's Practical Guide to Path Tracing](https://www.youtube.com/watch?v=frLwRLS_ZR0)
