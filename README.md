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
 <a href="#introduction">Introduction</a><br>
 <a href="#overview">Overview</a><br>
 <a href="#visual-overview">Visual Overview</a><br>
 <a href="#key-bindings">Key Bindings</a><br>
 <a href="#screenshots">Screenshots</a><br>
 <a href="#folder-structure">Folder Structure</a><br>
 <a href="#project-requirements---mandatory-part">Project Requirements - Mandatory Part</a><br>
 <a href="#important-guidelines">Important Guidelines</a><br>
 <a href="#window-and-graphics-requirements">Window and Graphics Requirements</a><br>
 <a href="#program-name">Program name</a><br>
 <a href="#usage">Usage</a><br>
 <a href="#scene-description-file-requirements">Scene Description File Requirements</a><br>
 <a href="#files-to-submit">Files to Submit</a><br>
 <a href="#allowed-external-functions">Allowed External Functions</a><br>
 <a href="#provided-resources">Provided Resources</a><br>
 <a href="#project-requirements---bonus-part">Project Requirements - Bonus Part</a><br>
 <a href="#minilibx-library">MiniLibX Library</a><br>
 <a href="#getting-started-with-minilibx">Getting Started with MiniLibX</a><br>
 <a href="#setting-up-minilibx">Setting Up MiniLibX</a><br>
 <a href="#including-minilibx-in-your-project">Including MiniLibX in Your Project</a><br>
 <a href="#introduction-to-minilibx">Introduction to MiniLibX</a><br>
 <a href="#manipulating-images-with-minilibx">Manipulating Images with MiniLibX</a><br>
 <a href="#event-handling-in-minilibx">Event Handling in MiniLibX</a><br>
 <a href="#window-handling-in-minilibx">Window Handling in MiniLibX</a><br>
 <a href="#drawing-and-displaying-content-in-minilibx">Drawing and Displaying Content in MiniLibX</a><br>
 <a href="#theoretical-background">Theoretical Background</a><br>
 <a href="#evaluation-process">Evaluation Process</a><br>
 <a href="#correction-sheet">Correction Sheet</a><br>
 <a href="#developed-skills">Developed Skills</a><br>
 <a href="#support">Support</a><br>
 <a href="#references">References</a><br>
 <a href="#author">Author</a><br>
</p>
<br>

## Introduction

<p align="justify">

Welcome to the world of cub3d, your ultimate raycasting engine! This project is designed to immerse you in the fascinating realm of 3D environments, where you'll explore and navigate through a maze-like world using the power of raycasting.

Cub3d is a collaborative project that encourages teamwork and collaboration. It is meant to be completed by a team of two students, fostering the development of essential skills in collaboration and communication. In my case, I had the pleasure of working on this project with my teammate [@ffursini](https://github.com/ffursini).

In this project, you'll dive into the world of computer graphics and learn about the fundamentals of raycasting, a technique used to create a 3D perspective in a 2D environment. You'll have the opportunity to implement various features, such as rendering walls, handling player movement, and incorporating textures to enhance the visual experience.

By the end of this project, you'll have a solid understanding of raycasting and its applications in creating immersive 3D environments. So, get ready to embark on an exciting journey into the world of cub3d!

</p>
</br>

### Overview

<p align="justify">

This project involves understanding the principles of raycasting, handling user input, and rendering graphics. It serves as a stepping stone for students to explore graphics programming and game development.

Key Concepts Covered in cub3d:

- **Raycasting**: Understanding the fundamentals of raycasting, including ray-object intersection and distance calculation.
- **Graphics Programming**: Learning how to manipulate pixels, draw lines and shapes, and apply texture mapping.
- **Mathematics**: Applying trigonometry, vector mathematics, and matrix transformations to 3D rendering.
- **Game Loop**: Implementing a game loop for frame rendering, event handling, and timing synchronization.
- **Memory Management**: Efficiently managing dynamic memory allocation and resource management.
- **Software Design**: Organizing code in a modular and structured manner.
- **User Input Handling**: Processing real-time keyboard and mouse events.

</p>

### Visual Overview

#### Key Bindings
![Key Bindings](https://github.com/f-corvaro/CUB3D/blob/main/.extra/key.png)

#### Screenshots
![Screenshot 1](https://github.com/f-corvaro/CUB3D/blob/main/.extra/Screenshot.png)

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

### Window and Graphics Requirements

<p align="justify">

- You must use the miniLibX library, either the version available on the operating system or from its sources. 
- Ensure smooth management of your window, including tasks such as changing to another window and minimizing.
- Implement different wall textures (your choice) that vary depending on which side the wall is facing (North, South, East, West).
- Your program should allow setting different colors for the floor and ceiling.
- The program should display the image in a window and adhere to the following rules:
  - Use the left and right arrow keys to look left and right in the maze.
  - Use the W, A, S, and D keys to move the point of view through the maze.
  - Press ESC to close the window and quit the program cleanly.
  - Clicking on the red cross on the window's frame should also close the window and quit the program cleanly.
  - It is strongly recommended to use images from the minilibX library.

</p>

### Program name

`cub3D`

#### Usage

<p align="justify">

To run the program, use the following syntax:

```bash
./cub3D <path/to/map.cub>
```

</p>

### Scene Description File Requirements

<p align="justify">

Your program must take a scene description file with the `.cub` extension as its first argument.
The map in the file must consist of only 6 possible characters:
- 0 for an empty space.
- 1 for a wall.
- N, S, E, or W for the player's start position and spawning orientation.

Here is an example of a valid map:

```
111111
100101
101001
1100N1
111111
```

- The map must be surrounded by walls, otherwise the program should return an error.
- Each type of element can be separated by one or more empty lines, except for the map content which always has to be the last.
- Each type of information for an element can be separated by one or more spaces.
- The map must be parsed exactly as it appears in the file, including spaces within the map.
- Each element (except the map) starts with a type identifier (one or two characters), followed by specific information for each object in a strict order. For example:
  - North texture: `NO ./path_to_the_north_texture`
  - South texture: `SO ./path_to_the_south_texture`
  - West texture: `WE ./path_to_the_west_texture`
  - East texture: `EA ./path_to_the_east_texture`
  - Floor color: `F 220,100,0`
  - Ceiling color: `C 225,30,0`

Here is an example of the mandatory part with a minimalist `.cub` scene:

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

If any misconfiguration is encountered in the file, the program should exit and return `Error\n` followed by an explicit error message of your choice.

</p>

### Files to Submit

`Makefile, *.h, *.c`

### Allowed External Functions

<p align="justify">

The program requires the following functions and libraries:

- File I/O functions: `open`, `close`, `read`, `write`
- Standard I/O functions: `printf`
- Memory management functions: `malloc`, `free`
- Error handling functions: `perror`, `strerror`, `exit`
- Time functions: `gettimeofday`
- Math library functions: All functions from the math library (-lm compiler option, `man man 3 math`)
- MiniLibX functions: All functions from the MiniLibX library
- Custom library: `Libft` (allowed for use in the project)

</p>

## Provided Resources

<p align="justify">

The resources provided by 42 Roma Luiss for this project are available in [Resources](https://github.com/f-corvaro/CUB3D/tree/main/rescources) folder. 

</p>

## Project Requirements - Bonus Part

<p align="justify">

For additional points, you can consider implementing the following elements:

- Wall collisions: Add functionality to detect and handle collisions with walls in the maze.
- Minimap system: Create a separate window or overlay that displays a smaller version of the maze as a minimap.
- Doors: Implement doors that can open and close, allowing the player to interact with them.
- Animated sprites: Add animated sprites to the game, such as moving enemies or objects.
- Mouse rotation: Enable the rotation of the point of view using mouse input.

Please note that these bonus features will only be evaluated if your mandatory part is perfect.

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

In the Cub3D project, a solid understanding of mathematics is crucial, particularly in the areas of geometry and trigonometry. Raycasting, a technique used to render a 3D environment in a 2D game, heavily relies on these mathematical concepts.

Raycasting involves casting rays from the player's point of view and determining the intersections of these rays with the walls of the game world. By calculating the distance between the player and each wall, we can create the illusion of depth and perspective.

To achieve this, we need to use mathematical formulas such as the Pythagorean theorem to calculate distances and angles. Trigonometric functions like sine and cosine are used to determine the direction and position of the rays.

The raycasting process can be broken down into the following steps:

1. Determine the player's position and direction in the game world.
2. Cast a series of rays from the player's position, covering the player's field of view.
3. For each ray, calculate its direction and step size.
4. Check for intersections between the ray and the walls of the game world.
5. Calculate the distance between the player and the wall at the intersection point.
6. Use the distance to determine the height of the wall on the screen.
7. Draw the wall on the screen, taking into account its height and perspective.

By repeating this process for each column of the screen, we can render a 3D representation of the game world.

In addition to mathematics, the Cub3D project also involves parsing. Parsing is the process of analyzing a text file to extract meaningful information. In this project, we parse a map file that represents the game world.

The parsing part of the project involves reading the map file, validating its contents, and extracting relevant information such as the dimensions of the map, the player's starting position, and the layout of the walls. This information is then used to generate the game world and perform raycasting calculations.

To parse the map file, we need to implement algorithms that can handle different types of data, such as integers, characters, and strings. We also need to handle error cases, such as invalid map formats or missing information.

In addition to the raycasting and parsing aspects, it is important to consider the camera view height and field of view (FOV). The camera view height determines the height at which the player's eyes are positioned in the game world, affecting the perspective and depth perception. The FOV determines the width of the player's field of view, influencing the amount of the game world that is visible on the screen.

Understanding and properly setting the camera view height and FOV are crucial for achieving a realistic and immersive visual experience in the game.

Overall, a solid understanding of mathematics, parsing techniques, camera view height, and FOV is essential for successfully implementing the raycasting and parsing parts of the Cub3D project.

</p>
<br>

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

- [Cub3D Tutorial by Ahmed Fatir](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf): This tutorial provides a detailed explanation of the Cub3D project, covering topics such as raycasting, parsing, and camera view height. It is a valuable resource for understanding the implementation of the game.

- [42Docs Cub3D Project Guide](https://harm-smits.github.io/42docs/projects/cub3d): This guide offers comprehensive documentation on the Cub3D project, including step-by-step instructions, code examples, and explanations of key concepts. It is a useful reference for completing the project successfully.

- [MiniLibX Documentation](https://gontjarow.github.io/MiniLibX/): This documentation provides information on the MiniLibX library, which is used in the Cub3D project for window handling, event handling, and drawing graphics. It includes detailed explanations of the library's functions and usage examples.

- [Xlib Documentation](https://tronche.com/gui/x/xlib/): This documentation covers Xlib, the library that MiniLibX is built upon. It provides in-depth information on Xlib's functions and features, which are relevant for understanding the underlying mechanisms of MiniLibX.

- [Ray Casting Tutorial by F. Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/): This tutorial offers a comprehensive guide to raycasting, the technique used in Cub3D to render a 3D environment in a 2D game. It covers the mathematical concepts and algorithms involved in raycasting, making it a valuable resource for understanding the core mechanics of the project.

- [Calculating Heading in 2D Games using Trigonometric Functions](https://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/): This tutorial explains how to calculate the heading or direction of an object in a 2D game using trigonometric functions. It provides a clear explanation of the relevant mathematical concepts, which are essential for understanding the raycasting process in Cub3D.

- [42Docs MiniLibX Library Guide](https://harm-smits.github.io/42docs/libs/minilibx): This guide focuses specifically on the MiniLibX library used in the Cub3D project. It provides detailed documentation on the library's functions, data structures, and usage examples, making it a valuable resource for working with MiniLibX effectively.

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>