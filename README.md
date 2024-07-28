<h1 align="center"><a href="https://github.com/f-corvaro/CUB3D">
	<img src="https://github.com/f-corvaro/CUB3D/blob/main/.extra/cub3d.png" alt="cub3d">
  </a></h1>

<p align="center">
	<b><i>"Explore immersive 3D environments with cub3d, your ultimate raycasting engine."</i></b><br>
</p>

<p align="center" style="text-decoration: none;">
    <a href="https://github.com/f-corvaro/CUB3D/blob/main/.extra/en.subject.pdf"><img alt="subject" src="https://img.shields.io/badge/subject-CUB3D-yellow" /></a>
    <a href="https://github.com/f-corvaro/CUB3D"><img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/f-corvaro/CUB3D?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/CUB3D"><img alt="Code language count" src="https://img.shields.io/github/languages/count/f-corvaro/CUB3D?color=yellow" /></a>
    <a href="https://github.com/f-corvaro/CUB3D"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/f-corvaro/CUB3D?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/CUB3D"><img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/f-corvaro/CUB3D?color=yellow" /></a>
</p>

<h3 align="center">Index</h3>
<p align="center">

- [Introduction](#introduction)
	- [Overview](#overview)
	- [Visual Overview](#visual-overview)
		- [Demonstration](#demonstration)
		- [Key Bindings](#key-bindings)
		- [Screenshots](#screenshots)
- [Folder Structure](#folder-structure)


</p>
<br>

## Introduction

<p align="justify">

The project is designed to be completed by a team of two students, improving collaboration and teamwork skills. Personally, I completed this project with my teammate [@ffursini](https://github.com/ffursini).

</p>
</br>

### Overview

<p align="justify">

</p>

### Visual Overview

#### Demonstration

![Program Overview]()

#### Key Bindings
![Key Bindings]()

#### Screenshots
![Screenshot 1]()
![Screenshot 2]()

</p>

## Folder Structure

<p align="justify">

```
.
├── cub3D
│   ├── include
│   │   ├── cub3d.h
│   │   ├── error_messages.h
│   │   ├── functions.h
│   │   ├── key_mapping.h
│   │   ├── macro.h
│   │   ├── resolution_config.h
│   │   └── types.h
│   ├── lib
│   │   ├── libftprintf
│   │   └── mlx_linux
│   ├── maps
│   │   ├── error
│   │   │   ├── double_keys.cub
│   │   │   ├── empty_map.cub
│   │   │   ├── invalid_extension.cub
│   │   │   ├── invalid_path.cub
│   │   │   ├── map1.invalid
│   │   │   ├── uknown_key.cub
│   │   │   └── wall.cub
│   │   ├── map1.cub
│   │   └── map2.cub
│   ├── srcs
│   │   ├── map
│   │   │   ├── borders.c
│   │   │   ├── init_and_loading.c
│   │   │   ├── operations.c
│   │   │   ├── parser.c
│   │   │   ├── player.c
│   │   │   ├── utils.c
│   │   │   └── validation.c
│   │   ├── mlx
│   │   │   └── init.c
│   │   ├── player
│   │   │   ├── actions.c
│   │   │   ├── input_key.c
│   │   │   └── position.c
│   │   ├── raycast
│   │   │   ├── dda.c
│   │   │   ├── init.c
│   │   │   ├── player_movement.c
│   │   │   ├── render_engine.c
│   │   │   ├── render_utils.c
│   │   │   ├── utils.c
│   │   │   └── wall_projection_calculator.c
│   │   ├── system
│   │   │   ├── cleanup_op.c
│   │   │   ├── close_game.c
│   │   │   ├── error_handling.c
│   │   │   ├── init.c
│   │   │   ├── input_validation.c
│   │   │   ├── menu.c
│   │   │   ├── shutdown_game.c
│   │   │   ├── utils.c
│   │   │   └── utils2.c
│   │   ├── texture
│   │   │   ├── convert_and_load.c
│   │   │   ├── init.c
│   │   │   └── validation.c
│   │   └── main.c
│   ├── texture
│   │   ├── blue.xpm
│   │   ├── mossy.xpm
│   │   ├── purplestone.xpm
│   │   ├── redbrick.xpm
│   │   ├── sludge.invalid
│   │   ├── sludge.xpm
│   │   ├── warn.xpm
│   │   ├── wood.xpm
│   │   └── yellow.xpm
│   └── Makefile
```


## Project Requirements - Mandatory Part

### Important Guidelines:

<p align="justify">

- The project must be written in C, following the Norm guidelines.
- Functions should not have unexpected errors, such as segmentation faults or double frees. Avoid undefined behaviors.
- Properly free all dynamically allocated memory when necessary.
- Include a Makefile that compiles the source files with the flags -Wall, -Wextra, and -Werror. Use the cc compiler. The Makefile should not relink. It should include the rules $(NAME), all, clean, fclean, and re. Bonus points if additional rules are included.
- If allowed, use your libft. Copy its sources and Makefile into a libft folder. The project's Makefile should compile the library using its Makefile, and then compile the project.
- Do not use global variables.

</p>

### Window and Graphics Management

<p align="justify">



</p>

### Program name

`cub3D`

#### Usage

<p align="justify">

To run the program, use the following syntax:

```bash

```

</p>

#### Overview

<p align="justify">



</p>

### Files to Submit

`Makefile, *.h, *.c`

### Allowed External Functions

<p align="justify">



</p>

## Provided Resources

[macOS Resources](https://github.com/f-corvaro/CUB3D/tree/main/rescources_macos)

[Linux Resources](https://github.com/f-corvaro/CUB3D/tree/main/resources_linux)

<p align="justify">

The resources provided by 42 Roma Luiss for this project are available in both the macOS and Linux folders. These resources include:

- Different versions of the MinilibX library: the Sierra version for macOS and MinilibX-Linux for Linux

</p>

## Project Requirements - Bonus Part

<p align="justify">



</p>

## MiniLibX Library

### Getting Started with MiniLibX

<p align="justify">

The MiniLibX library is a lightweight X-Window interface library designed for students. It provides a simple and intuitive way to create graphical software without requiring extensive knowledge of X-Window programming. With MiniLibX, you can easily create windows, draw graphics, manage images, and handle basic events. It is a versatile library that allows you to develop interactive graphical applications and display images within a window. MiniLibX is available for both macOS and Linux systems and can be seamlessly integrated into your project. By using MiniLibX, you can streamline the process of working with the X-Window system, making it more accessible and efficient for your programming needs.

</p>

### Setting Up MiniLibX

<p align="justify">

To set up MiniLibX, follow these steps:

1. Choose the version of MiniLibX that is suitable for your system.
2. Extract the library and rename it to `mlx` for macOS or `mlx_linux` for Linux.
3. Install the required dependencies for MiniLibX on Linux by running the following command on Ubuntu:
   
  ```bash
  sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
  ```

4. Configure MiniLibX by running the `configure` script in the root of the repository.
   
  ```bash
  ./configure
  ```

  You should see the following message:

  ```bash
  configure [info] : Execute "make all" from file "test/makefile.gen"
  gcc -I/usr/include -O3 -I.. -g   -c -o main.o main.c
  gcc -o mlx-test main.o -L.. -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
  ```

  Note that the MLX library requires the use of the `make all` command, not just `make`.

By following these steps, you will have MiniLibX set up and ready to use in your project.

</p>

### Including MiniLibX in Your Project

<p align="justify">

To integrate MiniLibX into your project, you need to include the `mlx.h` header file. This file contains function prototypes for MiniLibX functions. Additionally, you need to link your software with the necessary libraries, including the MiniLibX library itself.

</p>

### Introduction to MiniLibX

<p align="justify">

To get started with MiniLibX, you need to establish a connection between your software and the display. This can be achieved by calling the `mlx_init` function, which returns a `void *` identifier for further library calls.

Once the connection is established, you can leverage various MiniLibX functions to manage windows, draw graphics, manipulate images, and handle keyboard or mouse events. Some of these functions include `mlx_new_window`, `mlx_pixel_put`, `mlx_new_image`, and `mlx_loop`.

If the `mlx_init()` function fails to set up the connection to the X server, it will return NULL. Otherwise, it will provide a non-null pointer as the connection identifier.

</p>

### Manipulating Images with MiniLibX

<p align="justify">

- `mlx_new_image`: This function creates a new image in memory. It requires the size of the image to be created and the connection identifier. The function returns a void pointer that can be used to manipulate the image later.

- `mlx_put_image_to_window`: This function displays an image on the screen. It requires identifiers for the connection to the display, the window to use, and the image. It also needs the coordinates where the image should be placed in the window.

- `mlx_get_data_addr`: This function returns information about the created image, allowing you to modify it later. It requires the image pointer and the addresses of three different valid integers. It returns a char pointer that represents the beginning of the memory area where the image is stored.

- `mlx_destroy_image`: This function destroys the given image.

- `mlx_get_color_value`: This function translates a standard RGB color parameter to fit the bits_per_pixel requirement of the image, making the color understandable to the X-Server.

- `mlx_xpm_to_image` and `mlx_xpm_file_to_image`: These functions create a new image and fill it using the specified xpm_data or filename. They handle transparency but may not be able to read all types of xpm images.

The three functions that create images, `mlx_new_image`, `mlx_xpm_to_image`, and `mlx_xpm_file_to_image`, will return NULL if an error occurs. Otherwise, they return a non-null pointer as an image identifier.

</p>

### Event Handling in MiniLibX

<p align="justify">

Event handling is an essential aspect of graphical software development. In MiniLibX, you can easily handle events such as key presses, mouse clicks, and window exposes. Here are some functions provided by MiniLibX for event handling:

- `mlx_loop`: This function creates an infinite loop that waits for an event and then calls a user-defined function associated with that event. It requires the connection identifier.

- `mlx_key_hook`, `mlx_mouse_hook`, `mlx_expose_hook`: These functions allow you to assign user-defined functions to specific events. For example, you can assign a function to be called when a key is pressed, a mouse button is clicked, or a window is exposed. These functions require the window identifier, a pointer to the function to be called, and a parameter that will be passed to the function every time it is called.

- `mlx_loop_hook`: This function allows you to assign a user-defined function that will be called when no event occurs. It requires the connection identifier, a pointer to the function to be called, and a parameter that will be passed to the function.

When an event occurs, MiniLibX calls the corresponding function with fixed parameters. For key and mouse events, additional information is passed, such as the keycode for the pressed key, the coordinates of the mouse click in the window, and which mouse button was pressed.

Additionally, MiniLibX provides a more generic access to all X-Window events through the `mlx_hook` function. This function allows you to handle any X-Window event by specifying the event and mask values.

</p>

### Window Handling in MiniLibX

<p align="justify">

- `mlx_new_window`: This function creates a new window on the screen. It requires the connection identifier, the size of the window, and the title of the window. The function returns a void pointer that serves as a window identifier for other MiniLibX calls.

- `mlx_clear_window`: This function clears the given window by filling it with black. It requires the connection identifier and the window identifier.

- `mlx_destroy_window`: This function destroys the given window. It requires the same parameters as `mlx_clear_window`.

The `mlx_new_window` function allows you to create multiple separate windows. If it fails to create a new window, it will return NULL. Otherwise, it returns a non-null pointer as a window identifier.

The `mlx_clear_window` and `mlx_destroy_window` functions do not return any values.

</p>

### Drawing and Displaying Content in MiniLibX

<p align="justify">

To create visually appealing graphics in MiniLibX, you can use the following functions:

- `mlx_pixel_put`: This function allows you to draw a pixel at specific coordinates and color in the window. The origin (0,0) is located at the upper left corner of the window, with the x and y axis pointing right and down, respectively. You need to provide the connection identifier, window identifier, coordinates, and color as parameters.

- `mlx_string_put`: This function enables you to display a string at specified coordinates and color in the window. The parameters are the same as `mlx_pixel_put`, but instead of drawing a pixel, the specified string will be displayed.

It's important to note that both functions only work within the specified window and cannot display content outside of it or in front of other windows.

The color parameter is an integer that encodes the desired color. The color is created by mixing three basic colors: red, green, and blue. Each color value ranges from 0 to 255 and represents the intensity of that color in the final color. To display the desired color, you need to set the appropriate values within the integer.

With these functions, you can create and display various graphics and text in your MiniLibX project.

</p>

## Theoretical Background

<p align="justify">

</p>

## Evaluation Process

### Correction Sheet

<p align="center">
<a href="https://github.com/f-corvaro/CUB3D"><img width="650" src="https://github.com/f-corvaro/CUB3D/blob/main/.extra/cub3d_cs.jpg">
</p>

## Developed Skills

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## Support

<p align="center">

If you find this repository helpful, please consider starring it to show your support. Your support is greatly appreciated!

</p>

<br>

## References

- []()

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>