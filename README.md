# MiniRT
This project aims to project some geometric shapes, such as a cylinder, a plane and a sphere, with the help of Ray-tracing.
> The concept behind this keyword is to simulate some objects that are in our vision, in other words if we project a ray into the frame and we find an intersection with an object (sphere, cylinder or plane) we have to color that pixel, but before that, we need to project a second ray to the light and check if there is any other object on the road by calculation the intersection for the second time, if we find an intersection with an object then we color our pixel with the shadow color, otherwise we color it with its color

Knowledge to have to accomplish this project
- Linear algebra (vectors, matrixes)
- Solving quadratic equations
- Intersection equations of spheres, cylinders and planes
- Understand the concept of ray-tracing (https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing)
- And of course a programming language

*To use this code you will have to download Minilibx library with the project*
### Setting up the project
```
git clone https://github.com/houssambourkane/42cursus-minirt.git minirt && cd minirt && make all
```
### Usage :
```
./miniRT scenes/all_shapes.rt
```
*You can replace _all_shapes.rt_ with another existing file that contains the map*

### Examples

<img src="https://github.com/jchakir/minirt/blob/master/first.png" />
<img src="https://github.com/jchakir/minirt/blob/master/second.png" />
<img src="https://github.com/jchakir/minirt/blob/master/third.png" />
