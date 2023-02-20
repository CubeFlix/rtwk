cmake_minimum_required(VERSION 3.2)

project(render)

set(SOURCES
	src/main.c
	src/ppm.c
	src/ray.c
	src/vec3.c
	src/sphere.c
	src/scene.c
	src/camera.c
)

add_executable(render ${SOURCES})
